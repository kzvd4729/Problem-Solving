/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/31/2019 11:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 794 ms                                          memory_used: 64000 KB                             
*  problem: https://codeforces.com/contest/1000/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
const int N=1e6;
int desc[N+2],low[N+2],tim,vis[N+2],sub[N+2],tmp[N+2],ans;
vector<int>adj[N+2],sp[N+2];map<pair<int,int>,int>mp;
void dfs1(int node,int pre)
{
  desc[node]=low[node]=++tim;vis[node]=1;
  for(int i=0;i<adj[node].size();i++)
  {
    int next=adj[node][i];
    if(!vis[next])
    {
      dfs1(next,node);
      low[node]=min(low[node],low[next]);
      if(low[next]>desc[node])
      {
        int uu=next,vv=node;
        if(uu>vv)swap(uu,vv);
        mp[{uu,vv}]=1;
      }
    }
    else if(next!=pre)
      low[node]=min(low[node],low[next]);
  }
}
void dfs2(int node)
{
  vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    sp[node].push_back(x);
    dfs2(x);
  }
}
void dfs3(int node)
{
  for(auto x:sp[node])
  {
    dfs3(x);
    int uu=x,vv=node;
    if(uu>vv)swap(uu,vv);
    sub[node]=max(sub[node],sub[x]+mp[{uu,vv}]);
  }
}
void dfs4(int node,int pr)
{
  ans=max(ans,pr+sub[node]);
  set<pair<int,int> >st;
  for(auto x:sp[node])
  {
    int uu=x,vv=node;
    if(uu>vv)swap(uu,vv);
    tmp[x]=sub[x]+mp[{uu,vv}];
    st.insert({tmp[x],x});
  }
  for(auto x:sp[node])
  {
    int uu=x,vv=node;
    if(uu>vv)swap(uu,vv);
    st.erase({tmp[x],x});
    int mx=0;
    if(st.size())
      mx=max(mx,st.rbegin()->first);
    st.insert({tmp[x],x});
    dfs4(x,max(mx,pr)+mp[{uu,vv}]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(1,-1);memset(vis,0,sizeof(vis));
  dfs2(1);dfs3(1);dfs4(1,0);cout<<ans<<endl;
  return 0;
}