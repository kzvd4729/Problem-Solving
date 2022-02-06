/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/20/2019 15:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1762 ms                                         memory_used: 31600 KB                             
*  problem: https://codeforces.com/contest/360/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e3;
long aa[N+2],n,k,x,dp[N+2][N+2];
long dfs(long i,long j)
{
 if(i>n)return 0;
 if(dp[i][j]!=-1)return dp[i][j];
 long lt,rt,id=i-j-1,now=1e9;
 if(id==0)lt=-1e18,rt=1e18;
 else lt=aa[id]-x*(j+1),rt=aa[id]+x*(j+1);
 now=min(now,1+dfs(i+1,j+1));
 if(aa[i]>=lt&&aa[i]<=rt)
  now=min(now,dfs(i+1,0));
 return dp[i][j]=now;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>n>>k;
 for(long i=1;i<=n;i++)cin>>aa[i];
 long lo=0,hi=2e9,md,ans;
 while(lo<=hi)
 {
  md=(lo+hi)/2;x=md;
  memset(dp,-1,sizeof(dp));
  if(min(dfs(2,0),1+dfs(2,1))<=k)
   ans=md,hi=md-1;
  else lo=md+1;
  //cout<<md<<" "<<min(dfs(2,0),1+dfs(2,1))<<endl;
 }
 cout<<ans<<endl;
 return 0;
}