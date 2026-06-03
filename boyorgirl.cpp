#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;  // Assuming the input is a string
int flag=0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) {
                flag++;
            }
        }
    }
            flag= s.size() - flag;

    if (flag % 2 != 0)
            cout << "CHAT WITH HER!" << endl;
        else
            cout << "IGNORE HIM!" << endl;

    return 0;
}
