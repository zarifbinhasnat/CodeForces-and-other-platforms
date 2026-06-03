#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    string s;
    cin >> s;

    bool present[26] = {false};

    for (char &character : s) {
        character = tolower(character);

        if (character >= 'a' && character <= 'z') {
            present[character - 'a'] = true;
        }
    }

    bool allLettersPresent = all_of(begin(present), end(present), [](bool x) { return x; });

    if (allLettersPresent)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
