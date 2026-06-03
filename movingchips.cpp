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
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        // Count the number of ones and zeros
        int ones = count(nums.begin(), nums.end(), 1);
        int zeros = n - ones;

        // Find the first occurrence of 1
        int firstOneIndex = find(nums.begin(), nums.end(), 1) - nums.begin();

        // If all ones are consecutive, output 0
        if (ones == n - firstOneIndex) {
            cout << 0 << endl;
            continue;
        }

        int cnt = 0;
        int rightmostZeroIndex = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 1) {
                cnt++;
                if (cnt == ones) break; // If we have the required number of ones, stop
                // Find the rightmost zero before the rightmost one
                while (nums[rightmostZeroIndex] != 0) {
                    rightmostZeroIndex--;
                }
                // Swap the rightmost zero and the current one
                swap(nums[rightmostZeroIndex], nums[i]);
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
