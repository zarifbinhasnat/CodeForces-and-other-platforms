#include<bits/stdc++.h>
using namespace std;
void solve() {
    int gridSize;
    cin >> gridSize;

    int permLength = 2 * gridSize;

    // Initialize permutation result and used-number tracking
    vector<int> permutation(permLength + 1, 0);    // 1-based indexing
    vector<bool> isUsed(permLength + 1, false);    // Tracks used numbers from 1 to 2n

    // Read the grid and fill permutation[i + j] = value
    for (int row = 1; row <= gridSize; row++) {
        for (int col = 1; col <= gridSize; col++) {
            int value;
            cin >> value;

            int position = row + col;
            permutation[position] = value;
            isUsed[value] = true;
        }
    }

    // Output the reconstructed permutation
    for (int index = 1; index <= permLength; index++) {
        if (permutation[index] != 0) {
            cout << permutation[index] << " ";
        } else {
            // Find the smallest unused number and place it here
            for (int candidate = 1; candidate <= permLength; candidate++) {
                if (!isUsed[candidate]) {
                    isUsed[candidate] = true;
                    cout << candidate << " ";
                    break;
                }
            }
        }
    }

    cout << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
       solve();
        
    }


    return 0;
}
