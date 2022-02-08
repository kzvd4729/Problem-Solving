/****************************************************************************************
*  @author: kzvd4729                                         created: 12-04-2018 15:17:35                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 118.1M                               
*  problem: https://www.codechef.com/APRIL18A/problems/VAIMIN
****************************************************************************************/
#include<bits/stdc++.h>
const long mod=1e9+7;
using namespace std;
long long p,q,c,m,dp[3003][3003],x,y;
int vis[3003][3003];
int main()
{       
scanf("%lld%lld%lld%lld",&p,&q,&c,&m);
while(m--)
{
scanf("%lld%lld",&x,&y);
if(x<=3000&&y<=3000)vis[x][y]=1;   
}
dp[0][0]=1;
for(int i=0;i<=p;i++)
{
for(int j=0;j<=q;j++)
{
if(vis[i][j])dp[i][j]=0;
dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
if(i-j>c)dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
}
}
cout<<dp[p][q]%mod<<endl;
return 0;
}