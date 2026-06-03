#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <memory>   // for std::unique_ptr if needed

#include "Faction.h"
#include "DerivedFactions.h"

// ---------------------- Decision Structures ----------------------
struct DecisionOption {
    std::string text;              // Option description
    int moraleEffect;
    int resourceEffect;
    int influenceEffect;
    std::string mapID;             // ID/path of the image to load in the image window
    struct DecisionNode* nextNode; // pointer to next decision node
    std::string outcome;           // Terminal outcome text (if non-empty)
};

struct DecisionNode {
    std::string question;                // Question or prompt
    std::vector<DecisionOption> options; // Available options
};

// ---------------------- Example: Build a Simple Decision Tree ----------------------
DecisionNode* buildDecisionTree() {
    // We'll use static so these remain alive throughout the program (avoid local scope).
    static DecisionNode node1;
    static DecisionNode node2;

    // Node1
    node1.question = "The British impose new cartridges. Revolt immediately?";
    
    // Option1A
    static DecisionOption opt1a {
        "1) Revolt Now",
        +20,  // morale
        -10,  // resources
        +10,  // influence
        "assets/map1.png",  // load this map in the right window
        &node2,             // next node
        ""                  // no terminal outcome
    };
    // Option1B
    static DecisionOption opt1b {
        "2) Delay Action",
        -10,  // morale
        +5,   // resources
        -5,   // influence
        "assets/map2.png", // different map
        &node2,            // next node
        ""
    };

    node1.options.push_back(opt1a);
    node1.options.push_back(opt1b);

    // Node2
    node2.question = "Form alliances with neighboring princes?";

    static DecisionOption opt2a {
        "1) Yes, form alliances",
        +10,
        +10,
        +10,
        "assets/map1.png",
        nullptr, // no further node
        "Outcome: You gained valuable allies but also complicated loyalties."
    };
    static DecisionOption opt2b {
        "2) No, remain isolated",
        -5,
        0,
        -10,
        "assets/map2.png",
        nullptr,
        "Outcome: You stand alone; morale and influence dwindle."
    };

    node2.options.push_back(opt2a);
    node2.options.push_back(opt2b);

    // Return the pointer to the first node
    return &node1;
}

// ---------------------- Main Function ----------------------
int main() {
    // 1) Create two windows: left for decisions, right for images
    sf::RenderWindow decisionWindow(sf::VideoMode(600, 400), "Decision Window");
    decisionWindow.setPosition({100, 100});

    sf::RenderWindow imageWindow(sf::VideoMode(600, 400), "Map Window");
    imageWindow.setPosition({720, 100});

    // 2) Load a font for text
    sf::Font font;
    if (!font.loadFromFile("assets/font.ttf")) {
        std::cerr << "Error loading font!\n";
        return -1;
    }

    // 3) Create a faction instance (for demonstration)
    SepoyFaction myFaction; // or DeobandiFaction, INAFaction

    // 4) Build a decision tree
    DecisionNode* currentNode = buildDecisionTree();

    // 5) Prepare text objects to display the question, options, and faction stats
    sf::Text questionText;
    questionText.setFont(font);
    questionText.setCharacterSize(24);
    questionText.setFillColor(sf::Color::White);

    // We'll store the options in a vector of sf::Text each frame
    std::vector<sf::Text> optionTexts;

    // A text to show final outcome or faction stats
    sf::Text resultText;
    resultText.setFont(font);
    resultText.setCharacterSize(20);
    resultText.setFillColor(sf::Color::Yellow);

    // 6) Prepare the map sprite in the image window
    sf::Texture mapTexture;
    sf::Sprite mapSprite;

    // Helper to load a map image
    auto loadMap = [&](const std::string& path){
        if (!mapTexture.loadFromFile(path)) {
            std::cerr << "Could not load map: " << path << "\n";
            return;
        }
        mapSprite.setTexture(mapTexture, true);

        // Scale to fit the window if desired
        float windowW = (float)imageWindow.getSize().x;
        float windowH = (float)imageWindow.getSize().y;
        float scaleX = windowW / mapSprite.getLocalBounds().width;
        float scaleY = windowH / mapSprite.getLocalBounds().height;
        mapSprite.setScale(scaleX, scaleY);
    };

    // We can initially load a default map if we like
    loadMap("assets/map1.png"); 

    // We'll track if we reached a terminal outcome (i.e., no nextNode or we have outcome text)
    bool done = false;
    std::string outcome;  // store the final outcome

    // 7) Main loop
    while (decisionWindow.isOpen() && imageWindow.isOpen()) {
        sf::Event event;
        
        // ----------- DECISION WINDOW EVENTS -----------
        while (decisionWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                decisionWindow.close();
            }
            else if (event.type == sf::Event::KeyPressed && !done && currentNode) {
                // Check if user pressed 1 or 2, etc.
                // Convert them to index in currentNode->options
                int optionIndex = -1;
                if (event.key.code == sf::Keyboard::Num1) optionIndex = 0;
                else if (event.key.code == sf::Keyboard::Num2) optionIndex = 1;
                else if (event.key.code == sf::Keyboard::Num3) optionIndex = 2; // if you had more options

                if (optionIndex >= 0 && optionIndex < (int)currentNode->options.size()) {
                    // Apply the decision
                    auto& choice = currentNode->options[optionIndex];

                    // 1) Update faction stats
                    myFaction.updateStats(choice.moraleEffect, choice.resourceEffect, choice.influenceEffect);

                    // 2) Load map
                    if (!choice.mapID.empty()) {
                        loadMap(choice.mapID); 
                    }

                    // 3) If outcome is non-empty => terminal
                    if (!choice.outcome.empty()) {
                        outcome = choice.outcome;
                        done = true;
                        // The node is effectively ended
                        currentNode = nullptr;
                    }
                    else {
                        // Move on to next node
                        currentNode = choice.nextNode;
                        if (!currentNode) {
                            // This means no further decisions
                            done = true;
                            outcome = "No further decisions. Game concluded.";
                        }
                    }
                }
            }
        }

        // ----------- IMAGE WINDOW EVENTS -----------
        while (imageWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                imageWindow.close();
            }
        }

        // ----------- DECISION WINDOW DRAWING -----------
        decisionWindow.clear(sf::Color::Blue);

        // If we are not done, show the question and options
        if (!done && currentNode) {
            questionText.setString(currentNode->question);
            questionText.setPosition(20.f, 20.f);
            decisionWindow.draw(questionText);

            optionTexts.clear();
            for (size_t i = 0; i < currentNode->options.size(); i++) {
                sf::Text text;
                text.setFont(font);
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::White);
                text.setString(currentNode->options[i].text);
                text.setPosition(20.f, 70.f + (float)i*30.f);
                optionTexts.push_back(text);
            }
            // Draw them
            for (auto& t : optionTexts) {
                decisionWindow.draw(t);
            }

            // Also show faction stats
            std::string stats = "Faction: " + myFaction.getName() + 
                "\nMorale: " + std::to_string(myFaction.getMorale()) +
                "\nResources: " + std::to_string(myFaction.getResources()) +
                "\nInfluence: " + std::to_string(myFaction.getInfluence());
            resultText.setString(stats);
            resultText.setPosition(400.f, 20.f);
            decisionWindow.draw(resultText);
        }
        else {
            // We reached an outcome
            sf::Text doneText;
            doneText.setFont(font);
            doneText.setCharacterSize(24);
            doneText.setFillColor(sf::Color::Yellow);
            doneText.setString(outcome);
            doneText.setPosition(20.f, 20.f);
            decisionWindow.draw(doneText);

            // Show final stats, too
            std::string stats = "Faction: " + myFaction.getName() + 
                "\nMorale: " + std::to_string(myFaction.getMorale()) +
                "\nResources: " + std::to_string(myFaction.getResources()) +
                "\nInfluence: " + std::to_string(myFaction.getInfluence());
            resultText.setString(stats);
            resultText.setPosition(20.f, 80.f);
            decisionWindow.draw(resultText);
        }
        decisionWindow.display();

        // ----------- IMAGE WINDOW DRAWING -----------
        imageWindow.clear(sf::Color::Black);
        // Draw the map sprite
        imageWindow.draw(mapSprite);
        imageWindow.display();
    }

    return 0;
}
