/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-23 16:08:39                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 28                                         memory_used (MB): 6.9                             
*  problem: https://vjudge.net/problem/LightOJ-1063
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int desc[N+2],low[N+2],ap[N+2],vis[N+2];
int n,m,t,tc,tim,u,v;
vector<int>adj[N+2];
void dfs(int node,int pre)
{
  desc[node]=low[node]=++tim;
  vis[node]=1;
  int child=0;
  for(int i=0;i<adj[node].size();i++)
  {
    int next=adj[node][i];
    if(!vis[next])
    {
      child++;
      dfs(next,node);
      low[node]=min(low[node],low[next]);
      if(pre!=-1&&low[next]>=desc[node])
        ap[node]=1;
    }
    else if(next!=pre)
      low[node]=min(low[node],desc[next]);
  }
  if(pre==-1&&child>1)ap[node]=1;
}
int main()
{
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      adj[i].clear();
    for(int i=1;i<=m;i++)
    {
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    tim=0;
    memset(vis,0,sizeof(vis));
    memset(ap,0,sizeof(ap));
    dfs(1,-1);
    for(int i=1;i<=n;i++)
      ap[i]+=ap[i-1];
    cout<<"Case "<<++tc<<": "<<ap[n]<<endl;
  }
  return 0;
}