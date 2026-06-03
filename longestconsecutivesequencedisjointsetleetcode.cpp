#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)==s.end())//if the number is the starting number of the sequence
            {
                int j=nums[i];
                //find the length of the sequence
                while(s.find(j)!=s.end())
                {
                    j++;
                }
                //update the answer
                ans=max(ans,j-nums[i]);
            }
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    vector<int> nums={100,4,200,1,3,2};
    cout<<obj.longestConsecutive(nums);
}
