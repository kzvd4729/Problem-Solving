/****************************************************************************************
*  @author: kzvd4729                                         created: 01/28/2022 20:36                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 316 ms                                          memory_used: 115.1 MB                             
*  problem: https://leetcode.com/problems/solving-questions-with-brainpower
****************************************************************************************/
class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) 
    {
        int n=q.size();
        vector<long long>dp(n+2,0);
                for(int i=n-1;i>=0;i--)
        {
            dp[i]=dp[i+1];
            dp[i]=max(dp[i], q[i][0] + dp[min(n,1+i+q[i][1])] );
        }
        return dp[0];
    }
};