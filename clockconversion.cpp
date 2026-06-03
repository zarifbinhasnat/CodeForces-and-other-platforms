#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        
        int hours = stoi(s.substr(0, 2));
        int minutes = stoi(s.substr(3, 2));

        if (hours >= 12) {
            if (hours > 12) hours -= 12;
            cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << " PM" << endl;
        } else {
            if (hours == 0) hours = 12;
            cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << " AM" << endl;
        }
    }

    return 0;
}
