/****************************************************************************************
*  @author: kzvd4729                                         created: 06/07/2021 19:01                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 16 ms                                           memory_used: 13.6 MB                              
*  problem: https://leetcode.com/problems/min-cost-climbing-stairs
****************************************************************************************/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int a=cost[0],b=cost[1];
        for(int i=2,sz=cost.size();i<sz;i++)
        {
            int tb=b;
            b=cost[i]+min(a,b);
            a=tb;
        }
        return min(a,b);
    }
};