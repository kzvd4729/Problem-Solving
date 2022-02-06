/****************************************************************************************
*  @author: kzvd4729                                         created: 11/06/2019 08:09                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 84 ms                                           memory_used: 14.7 MB                              
*  problem: https://leetcode.com/problems/check-if-it-is-a-good-array
****************************************************************************************/
class Solution {
public:
    bool isGoodArray(vector<int>& nums) 
    {
      int gc=0;
      for(auto x:nums)
        gc=__gcd(gc,x);
      return gc==1;
    }
};