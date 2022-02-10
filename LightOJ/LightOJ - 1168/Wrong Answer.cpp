/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-31 15:15:02                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1168
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int t,tc,n,k,in[N+2],out[N+2];
int desc[N+2],anc[N+2],low[N+2],tim,stacked[N+2];
vector<int>adj[N+2],root;
set<int>_set;
stack<int>st;
void _clear(void)
{
  for(int i=1;i<=N;i++)
  {
    adj[i].clear();
    desc[i]=0;
    in[i]=0;
    out[i]=0;
  }
  tim=0;
  root.clear();
  _set.clear();
}
void tarjan(int node)
{
  desc[node]=low[node]=++tim;
  st.push(node);
  stacked[node]=1;
  for(int i=0;i<adj[node].size();i++)
  {
    int next=adj[node][i];
    if(!desc[next])
    {
      tarjan(next);
      low[node]=min(low[node],low[next]);
    }
    else if(stacked[next])
      low[node]=min(low[node],low[next]);
  }
  if(desc[node]==low[node])
  {
    int now=-1;
    while(now!=node)
    {
      now=st.top();
      st.pop();
      stacked[now]=0;
      anc[now]=node;
    }
    root.push_back(node);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    _clear();
    cin>>n;
    while(n--)
    {
      cin>>k;
      while(k--)
      {
        int u,v;
        cin>>u>>v;
        u++,v++;
        adj[u].push_back(v);
        _set.insert(u);
        _set.insert(v);
      }
    }
    vector<int>nodes;
    nodes.assign(_set.begin(),_set.end());
    for(int i=0;i<nodes.size();i++)
    {
      int x=nodes[i];
      if(desc[x])continue;
      tarjan(x);
    }
    cout<<root.size()<<endl;
    for(int i=0;i<nodes.size();i++)
    {
      int x=nodes[i];
      for(int j=0;j<adj[x].size();j++)
      {
        int xx=adj[x][j];
        if(anc[x]==anc[xx])continue;
        out[anc[x]]++;
        in[anc[xx]]++;
      }
    }
    int a=0,b=0;
    for(int i=0;i<root.size();i++)
    {
      int x=root[i];
      if(in[x]==0)a++;
      if(out[x]==0)b++;
    }
    if(a>=2||b>=2)cout<<"Case "<<++tc<<": NO"<<endl;
    else cout<<"Case "<<++tc<<": YES"<<endl;
  }
  return 0;
}