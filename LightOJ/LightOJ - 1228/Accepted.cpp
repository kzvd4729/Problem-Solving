/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-31 22:39:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1228
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,mt[12+2][12+2],dp[(1<<12)+2][12][12];
int dfs(int msk,int ls,int k)
{
  if(k<0)return 0;
  if(msk==(1<<n)-1)return (bool)(!k);
  if(dp[msk][ls][k]!=-1)return dp[msk][ls][k];
  int now=0;
  for(int i=0;i<n;i++)
  {
    if(msk&(1<<i))continue;
    now+=dfs(msk|(1<<i),i,k-mt[ls][i]);
  }
  return dp[msk][ls][k]=now;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    memset(mt,0,sizeof(mt));
    int k,q;cin>>n>>k>>q;
    for(int i=0;i<n;i++)
    {
      int x;cin>>x;
      while(x--)
      {
        int z;cin>>z;z--;
        mt[z][i]=1;
      }
    }
    memset(dp,-1,sizeof(dp));
    cout<<"Case "<<++tc<<":\n";
    while(q--)
    {
      int r;cin>>r;int ans=0;
      for(int i=0;i*k<=r&&i<n;i++)
        ans+=dfs(0,12,i);
      cout<<ans<<'\n';
    }
  }
  return 0;
}