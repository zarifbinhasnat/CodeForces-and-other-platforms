#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> grid(n);
        for(int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        // Vector to store the count of '1's in each row
        vector<int> onesInRow;
        
        // Count the number of '1's in each row
        for(int i = 0; i < n; i++) {
            int cnt = 0; // Reset count for each row
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                }
            }
            if(cnt > 0)
            onesInRow.push_back(cnt);
        }

        // Check if all elements in onesInRow are the same
        bool isSquare = true;
        for(int i = 1; i < onesInRow.size(); i++) {
            if(onesInRow[i] != onesInRow[i - 1]) {
                isSquare = false;
                break;
            }
        }

        // Output the result
        if(isSquare) {
            cout << "SQUARE" << endl;
        } else {
            cout << "TRIANGLE" << endl;
        }
    }
    return 0;
}
