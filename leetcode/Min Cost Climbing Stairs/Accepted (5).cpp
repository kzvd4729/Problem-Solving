/****************************************************************************************
*  @author: kzvd4729                                         created: 06/07/2021 19:00                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 8 ms                                            memory_used: 13.4 MB                              
*  problem: https://leetcode.com/problems/min-cost-climbing-stairs
****************************************************************************************/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int a=cost[0],b=cost[1];
        for(int i=2;i<cost.size();i++)
        {
            int tb=b;
            b=cost[i]+min(a,b);
            a=tb;
        }
        return min(a,b);
    }
};