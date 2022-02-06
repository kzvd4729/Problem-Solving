/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 14:54                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 328 ms                                          memory_used: 81.8 MB                              
*  problem: https://leetcode.com/problems/jump-game-vi
****************************************************************************************/
class Solution {
public:
    int maxResult(vector<int>&a, int k) 
    {
        int n=a.size();
        deque<int>d;d.push_back(0);
        vector<int>dp(n);dp[0]=a[0];
                for(int i=1;i<(int)a.size();i++)
        {
            while((int)d.size() && d.front()<i-k)d.pop_front();
                        dp[i]=dp[d.front()]+a[i];
            while((int)d.size() && dp[d.back()]<dp[i])d.pop_back();
            d.push_back(i);
        }
        return dp.back();
    }
};