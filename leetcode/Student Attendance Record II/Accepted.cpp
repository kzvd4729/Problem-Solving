/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 00:09                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 180 ms                                          memory_used: 21.6 MB                              
*  problem: https://leetcode.com/problems/student-attendance-record-ii
****************************************************************************************/
const int mod=1e9+7;
int dp[100000+2][2+2][3+2];
int dfs(int i,int n,int a,int l)
{
    if(i>n)return 1;
        if(dp[i][a][l]!=-1)return dp[i][a][l];
        int ret=0;
    ret=(ret+dfs(i+1,n,a,0))%mod;
    if(a==0)ret=(ret+dfs(i+1,n,a+1,0))%mod;
    if(l<=1)ret=(ret+dfs(i+1,n,a,l+1))%mod;
        return dp[i][a][l]=ret;
}
class Solution {
public:
    int checkRecord(int n) 
    {
        memset(dp,-1,sizeof dp);
        return dfs(1,n,0,0);
    }
};