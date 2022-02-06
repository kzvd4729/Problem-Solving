/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2019 23:22                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 19700 KB                             
*  problem: https://codeforces.com/contest/723/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>adj[N+2];
int in[N+2],out[N+2];
vector<pair<int,int> >ed;
map<pair<int,int>,int>mp;
void dfs(int node)
{
  for(auto x:adj[node])
  {
    if(mp[{node,x}])continue;
    mp[{node,x}]=mp[{x,node}]=1;
    dfs(x);ed.push_back({node,x});
    out[node]++,in[x]++;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)adj[i].clear(),in[i]=0,out[i]=0;
    while(m--)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);adj[v].push_back(u);
    }
    mp.clear(),ed.clear();
    for(int i=1;i<=n;i++)
      dfs(i);
    //cout<<ed.size()<<endl;
    //if(ed.size()!=m)assert(0);
    int ans=0;
    for(int i=1;i<=n;i++)if(in[i]==out[i])ans++;
    cout<<ans<<"\n";
    for(auto x:ed)
      cout<<x.first<<" "<<x.second<<"\n";
  }
  return 0;
}