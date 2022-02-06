/****************************************************************************************
*  @author: kzvd4729                                         created: 07/19/2021 23:48                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 8 ms                                            memory_used: 13.8 MB                              
*  problem: https://leetcode.com/problems/min-cost-climbing-stairs
****************************************************************************************/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
                vector<int>dp(n);
                dp[0]=cost[0];
        dp[1]=cost[1];
                for(int i=2;i<n;i++)
        {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-2],dp[n-1]);
    }
};