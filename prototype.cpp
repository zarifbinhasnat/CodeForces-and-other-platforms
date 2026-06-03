#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <cstdlib> // for random events
using namespace std;

// Forward Declarations
class GameModel;
class GameView;
class GameControllerMVC;

// Utility Function for Random Events
int randomEvent() {
    return rand() % 3; // Generate a random number between 0 and 2
}

// Base Faction Class
class Faction {
public:
    Faction(const string& factionName) : name(factionName), influence(50) {}
    virtual void interact(const string& action, int& morale, int& resources) = 0;
    string getName() const { return name; }
    int getInfluence() const { return influence; }
    void adjustInfluence(int value) { influence += value; }

protected:
    string name;
    int influence;
};

// Derived Factions
class ReligiousFaction : public Faction {
public:
    ReligiousFaction() : Faction("Religious Faction") {}
    void interact(const string& action, int& morale, int& resources) override {
        if (action == "negotiate") {
            cout << name << ": Negotiations successful. Influence increased!\n";
            morale += 10;
            resources -= 10;
            adjustInfluence(15);
        } else if (action == "declare war") {
            cout << name << ": Declared war! Prepare for consequences.\n";
            morale -= 20;
            resources -= 20;
        }
    }
};

class TradeFaction : public Faction {
public:
    TradeFaction() : Faction("Trade Faction") {}
    void interact(const string& action, int& morale, int& resources) override {
        if (action == "negotiate") {
            cout << name << ": Trade routes established. Wealth increased!\n";
            morale += 5;
            resources += 20;
            adjustInfluence(10);
        } else if (action == "declare war") {
            cout << name << ": Declared war! Trade embargoes incoming.\n";
            morale -= 30;
            resources -= 50;
        }
    }
};

class RevolutionaryFaction : public Faction {
public:
    RevolutionaryFaction() : Faction("Revolutionary Faction") {}
    void interact(const string& action, int& morale, int& resources) override {
        if (action == "negotiate") {
            cout << name << ": Revolutionary demands accepted. Influence increased!\n";
            morale += 15;
            adjustInfluence(20);
        } else if (action == "declare war") {
            cout << name << ": Armed conflict initiated. Morale high, but resources depleted.\n";
            morale += 10;
            resources -= 40;
        }
    }
};

// Player Class
class Player {
public:
    Player(const string& playerName) : name(playerName), morale(100), resources(100) {}

    void displayStats() {
        cout << "\nPlayer: " << name
             << "\nMorale: " << morale
             << "\nResources: " << resources << "\n";
    }

    void adjustMorale(int value) { morale += value; }
    void adjustResources(int value) { resources += value; }

    bool isGameOver() const {
        return morale <= 0 || resources <= 0;
    }

private:
    string name;
    int morale;
    int resources;
};

// GameModel (Data)
class GameModel {
public:
    GameModel() : player("Hero") {
        factions.push_back(make_unique<ReligiousFaction>());
        factions.push_back(make_unique<TradeFaction>());
        factions.push_back(make_unique<RevolutionaryFaction>());
    }

    Player& getPlayer() { return player; }
    vector<unique_ptr<Faction>>& getFactions() { return factions; }

private:
    Player player;
    vector<unique_ptr<Faction>> factions;
};

// GameView (UI)
class GameView {
public:
    void renderPlayerStats(Player& player) {
        player.displayStats();
    }

    void renderFactions(const vector<unique_ptr<Faction>>& factions) {
        cout << "\nFactions Available:\n";
        for (size_t i = 0; i < factions.size(); ++i) {
            cout << i + 1 << ". " << factions[i]->getName()
                 << " (Influence: " << factions[i]->getInfluence() << ")\n";
        }
    }

    void renderRandomEvent(int eventCode) {
        switch (eventCode) {
        case 0:
            cout << "\nRandom Event: British crackdown on protests! Morale reduced.\n";
            break;
        case 1:
            cout << "\nRandom Event: Economic boom in your region! Resources increased.\n";
            break;
        case 2:
            cout << "\nRandom Event: Internal faction dispute weakens influence.\n";
            break;
        }
    }
};

// GameControllerMVC (Controller)
class GameControllerMVC {
public:
    GameControllerMVC(GameModel& model, GameView& view)
        : model(model), view(view) {}

    void processInput() {
        string action;
        int factionChoice;

        view.renderPlayerStats(model.getPlayer());
        view.renderFactions(model.getFactions());

        cout << "\nChoose a faction to interact with (1-" << model.getFactions().size() << "): ";
        cin >> factionChoice;
        cout << "Choose an action (negotiate/declare war): ";
        cin >> action;

        if (factionChoice > 0 && factionChoice <= (int)model.getFactions().size()) {
            model.getFactions()[factionChoice - 1]->interact(
                action, model.getPlayer().adjustMorale(), model.getPlayer().adjustResources());
        } else {
            cout << "Invalid choice. Skipping turn.\n";
        }

        // Trigger a random event
        int eventCode = randomEvent();
        view.renderRandomEvent(eventCode);

        // Apply random event effects
        switch (eventCode) {
        case 0: model.getPlayer().adjustMorale(-10); break;
        case 1: model.getPlayer().adjustResources(20); break;
        case 2: model.getFactions()[0]->adjustInfluence(-10); break; // Example: Religious faction weakened
        }
    }

private:
    GameModel& model;
    GameView& view;
};

int main() {
    srand(time(nullptr)); // Seed random events
    GameModel model;
    GameView view;
    GameControllerMVC controller(model, view);

    cout << "Welcome to the Independence Game!\n";

    while (!model.getPlayer().isGameOver()) {
        cout << "\n=== New Turn ===\n";
        controller.processInput();
    }

    cout << "\nGame Over! Thanks for playing.\n";
    return 0;
}
