#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 2 != 0) 
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            char current_char = 'A';
            for(int i = 0; i < n / 2; i++) {
                cout << current_char << current_char;
                current_char++; // Increment the character
            }
            cout << endl;
        }
    }
    return 0;
}
