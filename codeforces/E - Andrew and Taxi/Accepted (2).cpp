/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/14/2019 19:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 11300 KB                             
*  problem: https://codeforces.com/contest/1100/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int low[N+2],desc[N+2],in[N+2],out[N+2];
int n,m,stacked[N+2],tim,anc[N+2];
vector<int>dir[N+2],root;
stack<int>st;
struct data
{
  int a,b,c,d;
};
vector<data>ed;
void make_graph(int xx)
{
  for(int i=1;i<=n;i++)
  {
    dir[i].clear();desc[i]=0;
  }
  tim=0;root.clear();
  for(auto x:ed)
  {
    if(x.c>xx)dir[x.a].push_back(x.b);
  }
}
 /************ Topo Sort ***************/
vector<int>topo_sorted,topo[N+2];
int tp_vis[N+2];
void Topo_sort(int node)
{
  tp_vis[node]=1;
  for(auto x:topo[node])
  {
    if(tp_vis[x])continue;
    Topo_sort(x);
  }
  topo_sorted.push_back(node);
}
vector<int>Topological_Sort(int n)
{
  for(int i=1;i<=n;i++)
  {
    if(tp_vis[i])continue;
    Topo_sort(i);
  }
  reverse(topo_sorted.begin(),topo_sorted.end());
  return topo_sorted;
}
//////////////////////////////////////////
  /********** Strongly Connected Component **********/
void tarjan(int node)
{
  desc[node]=low[node]=++tim;
  st.push(node);stacked[node]=1;
  for(auto x:dir[node])
  {
    if(!desc[x])
    {
      tarjan(x);
      low[node]=min(low[node],low[x]);
    }
    else if(stacked[x])
      low[node]=min(low[node],low[x]);
  }
  if(low[node]==desc[node])
  {
    int now=-1;
    while(now!=node)
    {
      now=st.top();st.pop();
      stacked[now]=0;anc[now]=node;
    }
    root.push_back(node);
  }
}
void Strongly_Connected_Component(int n)
{
  for(int i=1;i<=n;i++)
  {
    if(desc[i])continue;
    tarjan(i);
  }
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ed.push_back({u,v,w,i});
  }
  int lo=0,hi=1e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;make_graph(md);
    Strongly_Connected_Component(n);
    if(root.size()==n)hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
  {
    make_graph(md);
    Strongly_Connected_Component(n);
    if(root.size()==n)break;
  }
   for(auto x:ed)
  {
    if(x.c>md)
    {
      topo[x.a].push_back(x.b);
    }
  }
  vector<int>aa=Topological_Sort(n);
   int rnk[N+2];
   for(int i=0;i<aa.size();i++)
    rnk[aa[i]]=i;
   vector<int>ans;
  for(auto x:ed)
  {
    if(x.c>md)continue;
    if(rnk[x.a]>rnk[x.b])
      ans.push_back(x.d);
  }
  cout<<md<<" "<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}