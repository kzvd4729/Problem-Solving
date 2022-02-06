/****************************************************************************************
*  @author: kzvd4729                                         created: 06/01/2021 03:00                         
*  solution_verdict: Time Limit Exceeded                     language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/first-missing-positive
****************************************************************************************/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
                int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            while(i+1!=nums[i] && nums[i]>=1 && nums[i]<=n)
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++)
            if(i+1!=nums[i])return i+1;
        return n+1;
    }
};