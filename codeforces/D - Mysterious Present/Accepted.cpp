/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2018 19:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/4/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int dp[N+2];
struct data
{
  int u,v,id;
}aa[N+2];
bool cmp(data A,data B)
{
  return A.u<B.u;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,x,y;cin>>n>>x>>y;int id=0;
  for(int i=1;i<=n;i++)
  {
    int u,v;cin>>u>>v;
    if(u<=x||v<=y)continue;
    aa[++id]={u,v,i};
  }
  if(id==0)cout<<0<<endl,exit(0);
  sort(aa+1,aa+id+1,cmp);
  int ans=0;
  for(int i=1;i<=id;i++)
  {
    int mx=0;
    for(int j=1;j<i;j++)
    {
      if(aa[j].u<aa[i].u&&aa[j].v<aa[i].v)mx=max(mx,dp[j]);
    }
    dp[i]=mx+1;ans=max(ans,dp[i]);
  }
  cout<<ans<<endl;
  vector<int>pr;int uu=1e9,vv=1e9;
  for(int i=id;i>=1;i--)
  {
    if(ans==0)break;
    if(dp[i]==ans&&aa[i].u<uu&&aa[i].v<vv)
    {
      ans--;pr.push_back(aa[i].id);
      uu=aa[i].u;vv=aa[i].v;
    }
  }
  reverse(pr.begin(),pr.end());
  for(auto x:pr)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}