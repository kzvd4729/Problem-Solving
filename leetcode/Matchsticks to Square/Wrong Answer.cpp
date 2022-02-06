/****************************************************************************************
*  @author: kzvd4729                                         created: 06/15/2021 20:00                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/matchsticks-to-square
****************************************************************************************/
class Solution {
public:
    bool makesquare(vector<int>& a) 
    {
        for(int i=(int)a.size()-1;i>=0;i--)
        {
            if(a[i]==0)a.erase(a.begin()+i);
        }
        int n=a.size();if(n==0)assert(0);
                vector<int>dp((1<<n),0);
                dp[0]=1;
        for(int i=1;i<(1<<n);i++)
        {
            long long sm=0;
            for(int j=0;j<n;j++)if(i&(1<<j))sm+=a[j];
                        for(int j=0;j<n;j++)
            {
                if((i&(1<<j))==0)continue;
                if((sm-1)/4==(sm-a[j])/4)dp[i]|=dp[i^(1<<j)];
            }
        }
        return dp[(1<<n)-1];
    }
};