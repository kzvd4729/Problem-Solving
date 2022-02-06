/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/12/2018 22:01                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 14100 KB                             
*  problem: https://codeforces.com/contest/1076/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int anc[N+2],parent[N+2];
vector<int>adj[N+2],ds[N+2];
map<pair<int,int>,int>mp;
int _find(int x)
{
  if(x==anc[x])return x;
  return anc[x]=_find(anc[x]);
}
struct edge
{
  int u,v,w,id;
}ed[N+2];
bool cmp(edge A,edge B)
{
  return A.w<B.w;
}
void dfs(int node,int par,int h)
{
  parent[node]=par;
  ds[h].push_back(node);
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,h+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ed[i]={u,v,w,i};
    if(u>v)swap(u,v);mp[{u,v}]=i;
  }
  sort(ed+1,ed+m+1,cmp);
  for(int i=1;i<=n;i++)anc[i]=i;
  set<int>st;
  for(int i=1;i<=m;i++)
  {
    int r1=_find(ed[i].u);
    int r2=_find(ed[i].v);
    if(r1==r2)continue;
    anc[r1]=r2;
    st.insert(ed[i].id);
    //cout<<ed[i].id<<endl;
    //cout<<ed[i].u<<"--"<<ed[i].v<<endl;
    adj[ed[i].u].push_back(ed[i].v);
    adj[ed[i].v].push_back(ed[i].u);
  }
  dfs(1,-1,0);
  for(int i=N;i>=0;i--)
  {
    if(st.size()<=k)break;
    for(auto x:ds[i])
    {
      if(st.size()<=k)break;
      int u=x,v=parent[x];
      if(u>v)swap(u,v);
      int xx=mp[{u,v}];
      if(st.find(xx)!=st.end())
        st.erase(xx);
    }
  }
  cout<<st.size()<<endl;
  for(auto x:st)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}