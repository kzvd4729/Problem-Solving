/****************************************************************************************
*  @author: kzvd4729                                         created: 06/01/2021 03:03                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 152 ms                                          memory_used: 66.1 MB                              
*  problem: https://leetcode.com/problems/first-missing-positive
****************************************************************************************/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
                int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>=1 && nums[i]<=n && nums[nums[i]-1]!=nums[i])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++)if(i+1!=nums[i])return i+1;
        return n+1;
    }
};