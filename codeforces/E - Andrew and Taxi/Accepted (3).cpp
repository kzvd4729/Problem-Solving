/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/14/2019 19:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 10500 KB                             
*  problem: https://codeforces.com/contest/1100/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,m;
struct data
{
  int a,b,c,d;
};
vector<data>ed;
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
int scc_desc[N+2],scc_low[N+2],scc_tim,scc_stacked[N+2],scc_anc[N+2];
vector<int>scc_dir[N+2],scc_root;stack<int>scc_st;
void Tarjan(int node)
{
  scc_desc[node]=scc_low[node]=++scc_tim;
  scc_st.push(node);scc_stacked[node]=1;
  for(auto x:scc_dir[node])
  {
    if(!scc_desc[x])
    {
      Tarjan(x);
      scc_low[node]=min(scc_low[node],scc_low[x]);
    }
    else if(scc_stacked[x])
      scc_low[node]=min(scc_low[node],scc_low[x]);
  }
  if(scc_low[node]==scc_desc[node])
  {
    int now=-1;
    while(now!=node)
    {
      now=scc_st.top();scc_st.pop();
      scc_stacked[now]=0;scc_anc[now]=node;
    }
    scc_root.push_back(node);
  }
}
void Strongly_Connected_Component(int n)
{
  for(int i=1;i<=n;i++)
  {
    if(scc_desc[i])continue;
    Tarjan(i);
  }
}
//////////////////////////////////////////////////////
 void make_graph(int xx)
{
  for(int i=1;i<=n;i++)
  {
    scc_dir[i].clear();scc_desc[i]=0;
  }
  scc_tim=0;scc_root.clear();
  for(auto x:ed)
  {
    if(x.c>xx)scc_dir[x.a].push_back(x.b);
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
    if(scc_root.size()==n)hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
  {
    make_graph(md);
    Strongly_Connected_Component(n);
    if(scc_root.size()==n)break;
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