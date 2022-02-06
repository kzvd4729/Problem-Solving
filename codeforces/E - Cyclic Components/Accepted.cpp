/****************************************************************************************
*  @author: * kzvd4729                                       created: May/06/2018 21:13                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 343 ms                                          memory_used: 21400 KB                             
*  problem: https://codeforces.com/contest/977/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5+2;
int n,m,vis[N],vs[N],root,f,ans,sz,ed,u,v;
vector<int>adj[N],now;
void find_sz(int node)
{
  vis[node]=1;
  now.push_back(node);
  sz++;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    find_sz(x);
  }
}
void find_edge(void)
{
  for(auto x:now)
    ed+=adj[x].size();
}
void check_cycle(int node,int par)
{
  if(vs[node]==1&&node==root)
  {
    f=1;
    return ;
  }
  if(vs[node])return ;
  vs[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    check_cycle(x,node);
    if(f)return ;
  }
  vs[node]=2;
}
void inc_cnt(void)
{
  int g=0;
  for(auto x:now)
    if(vs[x]==0||vs[x]==2)
      g=1;
  if(!g)ans++;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  while(m--)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    sz=0;
    now.clear();
    find_sz(i);
    ed=0;
    find_edge();
    ed/=2;
 //    if(i==3)
//    {
//      for(auto x:now)
//        cout<<x<<" ";
//      cout<<endl;
//    }
     //cout<<i<<" "<<sz<<" "<<ed<<endl;
     if(sz!=ed)continue;
    root=i;
    f=0;
    check_cycle(i,-1);
//    for(int i=3;i<=5;i++)
//    {
//      cout<<vs[i]<<" ";
//    }
//    cout<<endl;
    if(!f)continue;
    inc_cnt();
   }
  cout<<ans<<endl;
  return 0;
}