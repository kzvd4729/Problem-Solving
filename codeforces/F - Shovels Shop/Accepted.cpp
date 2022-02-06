/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/16/2019 22:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 31400 KB                             
*  problem: https://codeforces.com/contest/1154/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long inf=1e14;
long aa[N+2],bb[N+2],qm[N+2],mx[N+2],k;
long dp[2004];
vector<pair<long,long> >of;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m>>k;
  for(long i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
   for(long i=1;i<=k;i++)
  {
    qm[i]=qm[i-1]+aa[i];
    dp[i]=qm[i];
  }
  for(long i=1;i<=m;i++)
  {
    long u,v;cin>>u>>v;mx[u]=max(mx[u],v);
    if(mx[i]>i)assert(0);
  }
  for(long i=1;i<=k;i++)
    of.push_back({i,mx[i]});
  if(of.size()==0)cout<<qm[k]<<endl,exit(0);
  for(int i=1;i<=k;i++)
  {
    dp[i]=min(dp[i],dp[i-1]+aa[i]);
    for(auto x:of)
    {
      if(x.first<=i)
      {
        dp[i]=min(dp[i],qm[i]-qm[i-(x.first-x.second)]+dp[i-x.first]);
      }
    }
  }
  cout<<dp[k]<<endl;
  return 0;
}