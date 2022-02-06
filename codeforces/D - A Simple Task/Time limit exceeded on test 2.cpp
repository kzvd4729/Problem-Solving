/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2018 19:26                        
*  solution_verdict: Time limit exceeded on test 2           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/11/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=22;
int n,ans;
vector<int>adj[N+2];
void dfs(int st,int node,int par,int msk)
{
  for(auto x:adj[node])
  {
    if(x==par)continue;
    else if(x==st)ans++;
    else if(msk&(1<<x))continue;
    else dfs(st,x,node,msk|(1<<x));
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int msk=0;
  for(int i=0;i<n;i++)
  {
    msk|=(1<<i);dfs(i,i,-1,msk);
    //cout<<ans<<endl;
  }
  cout<<ans/2<<endl;
  return 0;
}