#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 

    int n;
    cin >> n;

    string s;
    cin >> s;

    int t = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'F')
            t += 10;
        else if (s[i] == 'T') {
            cout << "Alarm turned on after " << t << " minutes" << endl;
            return 0;
        }
    }

    cout << "The alarm never turned on" << endl;

    return 0;
}
