/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-30 19:58:22                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 370                                        memory_used (MB): 31.7                            
*  problem: https://vjudge.net/problem/SPOJ-CAPCITY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int desc[N+2],low[N+2],head[N+2],stacked[N+2];
int tim,n,m,out[N+2],scc;
vector<int>adj[N+2],dir[N+2],shead,_head[N+2];
stack<int>st;
void tarjan(int node)
{
  desc[node]=low[node]=++tim;
  st.push(node);
  stacked[node]=1;
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
  if(desc[node]==low[node])
  {
    scc++;
    shead.push_back(node);
    int now=-1,sz=0;
    while(now!=node)
    {
      now=st.top();
      st.pop();
      stacked[now]=0;
      head[now]=node;
      _head[node].push_back(now);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  for(int i=1;i<=m;i++)
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
  if(scc==1)
  {
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
      cout<<i<<" ";
    cout<<endl;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<dir[i].size();j++)
    {
      int x=dir[i][j];
      if(head[i]==head[x])continue;
      out[head[i]]++;
    }
  }
  int root;
  for(int i=0;i<shead.size();i++)
  {
    int x=shead[i];
    if(out[x]==0)
      root=x;
  }
  sort(_head[root].begin(),_head[root].end());
  cout<<_head[root].size()<<endl;
  for(int i=0;i<_head[root].size();i++)
    cout<<_head[root][i]<<" ";
  cout<<endl;
  return 0;
}