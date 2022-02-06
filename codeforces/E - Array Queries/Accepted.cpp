/****************************************************************************************
*  @author: kzvd4729                                         created: May/09/2019 12:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 592 ms                                          memory_used: 5700 KB                              
*  problem: https://codeforces.com/contest/797/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],dp[N+2],n,ans[N+2];
vector<pair<int,int> >qr[N+2];
int dfs(int node,int ad)
{
  if(node>n)return 0;
  if(dp[node]!=-1)return dp[node];
  return dp[node]=1+dfs(node+ad+aa[node],ad);
}
int dds(int node,int ad)
{
  if(node>n)return 0;
  return 1+dds(node+ad+aa[node],ad);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int p,k;cin>>p>>k;
    qr[k].push_back({p,i});
  }
  for(int i=1;i<=n;i++)
    sort(qr[i].begin(),qr[i].end());
  int sq=sqrt(n+1);
  for(int i=1;i<=sq;i++)
  {
    if(qr[i].size()==0)continue;
    memset(dp,-1,sizeof(dp));
    reverse(qr[i].begin(),qr[i].end());
    for(auto x:qr[i])
      ans[x.second]=dfs(x.first,i);
  }
  for(int i=sq+1;i<=n;i++)
  {
    if(qr[i].size()==0)continue;
    for(auto x:qr[i])
      ans[x.second]=dds(x.first,i);
  }
  for(int i=1;i<=q;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}