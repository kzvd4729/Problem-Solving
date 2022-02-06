/****************************************************************************************
*  @author: kzvd4729                                         created: 05/31/2021 01:03                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 8.5 MB                               
*  problem: https://leetcode.com/problems/maximum-gap
****************************************************************************************/
class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ret=0;
                for(int i=1;i<(int)nums.size();i++)
        {
            ret=max(ret,nums[i]-nums[i-1]);
        }
        return ret;
    }
};