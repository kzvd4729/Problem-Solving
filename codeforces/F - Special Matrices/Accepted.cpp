/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/10/2018 15:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/489/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
int n,m,fr[N+2];
long mod,dp[N+2][N+2];
long dfs(int on,int zr)
{
  if(zr==0&&on==0)return 1;
  if(dp[on][zr]!=-1)return dp[on][zr];
  long here=0;
  if(on>=2)here=(here+(on*(on-1))/2*dfs(on-2,zr))%mod;
  if(zr>=2)here=(here+(zr*(zr-1))/2*dfs(on+2,zr-2))%mod;
  if(on>0&&zr>0)here=(here+on*zr*dfs(on,zr-1))%mod;
  return dp[on][zr]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>mod;
  while(m--)
  {
    string s;cin>>s;
    for(int i=0;s[i];i++)
      fr[i+1]+=s[i]-'0';
  }
  int on=0,zr=0;
  for(int i=1;i<=n;i++)
  {
    if(fr[i]==0)zr++;
    else if(fr[i]==1)on++;
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(on,zr)<<endl;
  return 0;
}