#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int maxLength = 1;
        int currentLength = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                // Skip duplicates
                continue;
            } else if (nums[i] == nums[i - 1] + 1) {
                // Consecutive element found
                currentLength++;
            } else {
                // Reset current length
                currentLength = 1;
            }
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << obj.longestConsecutive(nums) << endl;
    return 0;
}