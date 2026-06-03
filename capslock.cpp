#include <iostream>
#include <cctype> // For the isupper and islower functions
#include <cstdio> // Add this header for freopen

using namespace std; // Add this line to use cin without std:: prefix

std::string fix_caps_lock(const std::string& word) {
    // Check if the word is all uppercase or all lowercase except for the first letter
    if (std::all_of(word.begin(), word.end(), ::isupper) ||
        (std::isupper(word[0]) && std::all_of(word.begin() + 1, word.end(), ::islower))) {
        
        // Change the case of all letters in the word
        std::string fixed_word = word;
        for (char& c : fixed_word) {
            if (std::isupper(c)) {
                c = std::tolower(c);
            } else {
                c = std::toupper(c);
            }
        }

        return fixed_word;
    } else {
        // If the rule cannot be applied, leave the word unchanged
        return word;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    std::cout << fix_caps_lock(s) << std::endl;  // Output: http

    return 0;
}
