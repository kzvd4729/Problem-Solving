/****************************************************************************************
*  @author: kzvd4729                                         created: 06/11/2021 15:13                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 228 ms                                          memory_used: 14.3 MB                              
*  problem: https://leetcode.com/problems/stone-game-vii
****************************************************************************************/
class Solution 
{
public:
    int dp[1000+2][1000+2];
    int dfs(vector<int>&a,int i,int j)
    {
        if(i>j)return 0;
                if(dp[i][j]!=-1)return dp[i][j];
                int ret=a[j]-a[i]-dfs(a,i+1,j);
                int cs=0;
        if(j)cs+=a[j-1];
        if(i)cs-=a[i-1];
                ret=max(ret,cs-dfs(a,i,j-1));
                return dp[i][j]=ret;
    }
    int stoneGameVII(vector<int>& a) 
    {
        vector<int>b=a;
        for(int i=1;i<(int)b.size();i++)b[i]+=b[i-1];
        memset(dp,-1,sizeof dp);
        return dfs(b,0,b.size()-1);
    }
};