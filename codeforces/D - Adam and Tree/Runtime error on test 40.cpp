/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/01/2019 20:30                        
*  solution_verdict: Runtime error on test 40                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 13800 KB                             
*  problem: https://codeforces.com/contest/442/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int par[N+2],aa[N+2],mx1[N+2],mx2[N+2],dp[N+2],prnt[N+2];
vector<int>adj[N+2];
set<pair<int,int> >st[N+2];
void dfs(int node)
{
  st[node].insert({0,0});
  st[node].insert({0,-1});
  for(auto x:adj[node])
  {
    dfs(x);
    st[node].insert({-dp[x],x});
  }
  auto it=st[node].begin();
  int a=-it->first;it++;int b=-it->first;
  if(node!=1)b++;dp[node]=max(a,b);
}
void upd(int node,int ch,int now)
{
  if(!node)return ;
  st[node].erase({-dp[ch],ch});
  dp[ch]=now;
  st[node].insert({-dp[ch],ch});
   auto it=st[node].begin();
  int a=-it->first;it++;int b=-it->first;
  if(node!=1)b++;
  if(dp[node]==max(a,b))return ;
    upd(par[node],node,max(a,b));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;n++;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;adj[x].push_back(i);
    aa[i]=x;par[i]=x;
  }
  dfs(1);
  // for(int i=1;i<=n;i++)
  //   cout<<dp[i];
  // cout<<endl;
   for(int i=n;i>1;i--)
  {
    prnt[i]=-st[1].begin()->first;
    upd(par[i],i,0);
  }
  for(int i=2;i<=n;i++)
    cout<<prnt[i]<<" ";
  cout<<endl;
  return 0;
}