/****************************************************************************************
*  @author: kzvd4729                                         created: 04/17/2021 20:42                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 236 ms                                          memory_used: 97.2 MB                              
*  problem: https://leetcode.com/problems/maximum-xor-for-each-query
****************************************************************************************/
class Solution {
public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int xx=0;
    for(int i=0;i<nums.size();i++)xx^=nums[i];
    vector<int>ret;
    while((int)nums.size())
    {
      int sm=0;
      for(int i=0;i<maximumBit;i++)
      {
        if((xx&(1<<i))==0)sm|=(1<<i);
      }
      ret.push_back(sm);
      xx^=nums.back();nums.pop_back();
    }
    return ret;
  }
};