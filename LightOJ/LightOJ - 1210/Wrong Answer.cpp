/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-31 22:36:14                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1210
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e4;
int t,tc,low[N+2],in[N+2],out[N+2],desc[N+2];
int n,m,stacked[N+2],tim,anc[N+2];
vector<int>dir[N+2],adj[N+2],root;
stack<int>st;
void tarjan(int u)
{
  desc[u]=low[u]=++tim;
  st.push(u);
  stacked[u]=1;
  for(int i=0;i<adj[u].size();i++)
  {
    int v=adj[u][i];
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
      stacked[u]=0;
      anc[now]=u;
    }
    root.push_back(u);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      dir[i].clear();
      adj[i].clear();
      desc[i]=0;
      in[i]=0;
      out[i]=0;
    }
    tim=0;
    root.clear();
    while(m--)
    {
      int u,v;
      cin>>u>>v;
      dir[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
      if(desc[i])continue;
      tarjan(i);
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<dir[i].size();j++)
      {
        int x=dir[i][j];
        if(anc[i]==anc[x])continue;
        out[anc[i]]++;
        in[anc[x]]++;
      }
    }
    int a=0,b=0;
    for(int i=0;i<root.size();i++)
    {
      int x=root[i];
      if(!in[x])a++;
      if(!out[x])b++;
    }
    cout<<"Case "<<++tc<<": "<<max(a,b)<<endl;
  }
  return 0;
}