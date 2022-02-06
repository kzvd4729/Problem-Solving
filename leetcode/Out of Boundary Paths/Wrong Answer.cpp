/****************************************************************************************
*  @author: kzvd4729                                         created: 06/24/2021 20:58                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/out-of-boundary-paths
****************************************************************************************/
class Solution 
{
public:
    static const int mod=1e9+7;
    int findPaths(int m, int n, int k, int R, int C) 
    {
        vector<vector<vector<int> > >dp(k+1,vector<vector<int> >(n+2,vector<int>(m+2,0)));
                for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=m+1;j++)
            {
                if((i==0) || (j==0) || (i==n+1) || (j==m+1))dp[0][i][j]=1;
            }
        }
        for(int l=1;l<=k;l++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    dp[l][i][j]=(dp[l][i][j]+dp[l-1][i-1][j])%mod;
                    dp[l][i][j]=(dp[l][i][j]+dp[l-1][i+1][j])%mod;
                    dp[l][i][j]=(dp[l][i][j]+dp[l-1][i][j-1])%mod;
                    dp[l][i][j]=(dp[l][i][j]+dp[l-1][i][j+1])%mod;
                }
            }
        }
        int ans=0;
        for(int l=0;l<=k;l++)ans=(ans+dp[l][R+1][C+1])%mod;
        return ans;
    }
};