/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/13/2019 22:32                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/1100/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e4;
int low[N+2],desc[N+2],in[N+2],out[N+2];
int n,m,stacked[N+2],tim,anc[N+2];
vector<int>dir[N+2],root;
stack<int>st;
struct data
{
  int a,b,c,d;
};
vector<data>ed;
void tarjan(int u)
{
  desc[u]=low[u]=++tim;
  st.push(u);
  stacked[u]=1;
  for(int i=0;i<dir[u].size();i++)
  {
    int v=dir[u][i];
    if(desc[v]==0)
    {
      tarjan(v);
      low[u]=min(low[u],low[v]);
    }
    else if(stacked[v])
      low[u]=min(low[u],low[v]);
  }
  if(low[u]==desc[u])
  {
    int now=-1;
    while(now!=u)
    {
      now=st.top();
      st.pop();
      stacked[now]=0;
      anc[now]=u;
    }
    root.push_back(u);
  }
}
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
     for(int i=1;i<=n;i++)
    {
      if(desc[i])continue;
      tarjan(i);
    }
    if(root.size()==n)hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
  {
    make_graph(md);
    for(int i=1;i<=n;i++)
    {
      if(desc[i])continue;
      tarjan(i);
    }
    if(root.size()==n)break;
  }
  for(auto x:ed)
  {
    if(x.c>md)
    {
      out[x.a]++;in[x.b]++;
    }
  }
  vector<int>ans;
  for(auto x:ed)
  {
    if(x.c>md)continue;
    if(in[x.a]==0)
    {
      in[x.b]++;
    }
    else
    {
      ans.push_back(x.d);
      in[x.a]++;
    }
  }
  cout<<md<<" "<<ans.size()<<endl;
  for(auto x:ans)cout<<x<<" ";
    cout<<endl;
  return 0;
}