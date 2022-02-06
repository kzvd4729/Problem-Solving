/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2019 17:01                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/962/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int lev[N+2],vis[N+2],prnt[N+2],cnt[N+2];
vector<int>adj[N+2],tree[N+2],lst[N+2];
vector<pair<int,int> >bk,ans;
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv,prnt[node]=par;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(vis[x])bk.push_back({node,x});
    else
    {
      tree[node].push_back(x);
      tree[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
void add(int node,int par)
{
  for(auto x:tree[node])
  {
    if(x==par)continue;
    add(x,node);cnt[node]+=cnt[x];
  }
}
void dds(int node,int par,int lv)
{
  for(auto v:lst[node])
  {
    if(lev[v]<lv)continue;
    ans.push_back({v,node});
    int x=node,u;
    while(true)
    {
      u=prnt[x];ans.push_back({u,x});if(u==v)break;
      x=u;
    }
  }
  for(auto x:tree[node])
  {
    if(x==par)continue;
    if(cnt[x]>1)dds(x,node,lev[x]);
    else dds(x,node,lv);
  }
}
int main()
{
  dont compile
  freopen("inp.txt","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,1);
  for(auto &x:bk)
  {
    if(lev[x.first]>lev[x.second])swap(x.first,x.second);
    cnt[x.second]++,cnt[x.first]--;
    lst[x.second].push_back(x.first);
  }
  for(auto x:bk)
    cout<<x.first<<" ** "<<x.second<<endl;
  add(1,-1);dds(1,-1,0);
  for(auto x:ans)
    cout<<x.first<<" --> "<<x.second<<endl;
  return 0;
}