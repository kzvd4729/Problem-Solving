/****************************************************************************************
*  @author: kzvd4729                                         created: 04/17/2021 20:32                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 16 ms                                           memory_used: 15.9 MB                              
*  problem: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing
****************************************************************************************/
class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int ret=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])continue;
            else
            {
                ret+=nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return ret;
    }
};