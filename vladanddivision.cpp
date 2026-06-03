#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minGroups(vector<int>& nums) {
    unordered_map<int, vector<int>> groups;
    
    for (int num : nums) {
        int mask = 1;
        for (int i = 0; i < 31; i++) {
            if (num & mask) {
                groups[i].push_back(num);
            }
            mask <<= 1;
        }
    }
    
    int minGroupCount = 0;
    for (auto& it : groups) {
        minGroupCount = max(minGroupCount, (int)it.second.size());
    }
    
    return minGroupCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        cout << minGroups(nums) << endl;
    }
    
    return 0;
}
