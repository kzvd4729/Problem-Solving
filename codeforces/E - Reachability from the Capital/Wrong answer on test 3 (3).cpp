/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/03/2018 18:43                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/999/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int n,m,c,u,v,head[N+2],in[N+2],out[N+2];
int desc[N+2],low[N+2],tim,stacked[N+2];
vector<int>adj[N+2];
stack<int>st;
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
      low[node]=min(low[node],desc[next]);
  }
  if(low[node]==desc[node])
  {
    int now=-1;
    while(now!=node)
    {
      now=st.top();
      st.pop();
      stacked[now]=0;
      head[now]=node;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>c;
  while(m--)
  {
    cin>>u>>v;
    adj[u].push_back(v);
  }
  for(int i=1;i<=n;i++)
    if(!desc[i])tarjan(i);
  for(int i=1;i<=n;i++)
  {
    int node=i;
    for(int j=0;j<adj[node].size();j++)
    {
      int next=adj[node][j];
      in[head[next]]++;
      out[head[node]]++;
    }
  }
  int cnt=0;
  for(int i=1;i<=n;i++)
    if(in[head[i]]==0)cnt++;
  cout<<cnt<<endl;
  return 0;
}