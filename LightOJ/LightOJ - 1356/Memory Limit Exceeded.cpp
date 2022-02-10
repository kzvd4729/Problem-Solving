/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-14 15:15:50                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1356
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5,R=4e4,inf=1e9;
int a,b,lft[R+2],rgt[R+2],dis[R+2],q[R+2];
vector<int>adj[R+2];
void clean()
{
  for(int i=1;i<=a;i++)
    lft[i]=0,adj[i].clear();
  for(int i=1;i<=b;i++)
    rgt[i]=0;
}
bool bfs(void)
{
  int sz=0;
  for(int i=1;i<=a;i++)
  {
    if(!lft[i])q[sz++]=i,dis[i]=0;
    else dis[i]=inf;
  }
  dis[0]=inf;
  for(int i=0;i<sz;i++)
  {
    int u=q[i];
    for(auto &v:adj[u])
    {
      if(dis[rgt[v]]<=dis[u]+1)continue;
      dis[rgt[v]]=dis[u]+1;
      if(rgt[v])q[sz++]=rgt[v];
    }
  }
  return dis[0]!=inf;
}
bool dfs(int u)
{
  if(!u)return true;
  for(auto &v:adj[u])
  {
    if(dis[u]+1==dis[rgt[v]])
    {
      if(dfs(rgt[v]))
      {
        lft[u]=v;rgt[v]=u;return true;
      }
    }
  }
  return false;
}
int hopkroft(void)
{
  int match=0;
  while(bfs())
  {
    for(int i=1;i<=a;i++)
    {
      if(dis[i])continue;
      if(dfs(i))match++;
    }
  }
  return match;
}
int vis[N+2],aa[R+2],col[R+2];
vector<int>prm[N+2];
void cal()
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
      prm[j].push_back(i),vis[j]=1;
  }
}
void color(int node,int cl)
{
  col[node]=cl;vis[node]=1;
  for(auto &x:adj[node])
    if(!vis[x])color(x,cl^1);
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  cal();int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
      cin>>aa[i],vis[aa[i]]=i;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<=n;i++)
    {
      for(auto &x:prm[aa[i]])
        if(vis[aa[i]/x])
          adj[i].push_back(vis[aa[i]/x]),adj[vis[aa[i]/x]].push_back(i);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
      if(vis[i]==0)color(i,0);
    a=n,b=n;
    for(int i=1;i<=n;i++)
      if(col[i])adj[i].clear();
    cout<<"Case "<<++tc<<": "<<n-hopkroft()<<endl;
    clean();
  }
  return 0;
}