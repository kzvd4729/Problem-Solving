/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/09/2018 19:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1200 ms                                         memory_used: 19000 KB                             
*  problem: https://codeforces.com/contest/342/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e8;
int n,m,u,v,t,x,dis[N+2];
int parent[N+2],level[N+2];
int sp[N+2][22];
vector<int>adj[N+2];
queue<int>q;
void dfs(int node,int par,int h)
{
  parent[node]=par;
  level[node]=h;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,h+1);
  }
}
void build(void)
{
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<=n;i++)sp[i][0]=parent[i];
  for(int j=1;j<=18;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[i][j-1]==-1)continue;
      sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int query(int u,int v)
{
  int ret=0;
  if(level[u]<level[v])swap(u,v);
  for(int i=18;i>=0;i--)
  {
    if(sp[u][i]==-1)continue;
    if(level[sp[u][i]]>=level[v])
    {
      u=sp[u][i];
      ret+=(1<<i);
    }
  }
  if(u==v)return ret;
  for(int i=18;i>=0;i--)
  {
    if(sp[u][i]==-1||sp[v][i]==-1)continue;
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i];
    v=sp[v][i];
    ret+=(2*(1<<i));
  }
  ret+=2;
  return ret;
}
void upd(void)
{
  while(q.size())
  {
    int node=q.front();
    q.pop();
    for(auto x:adj[node])
    {
      if(dis[node]+1<dis[x])
      {
        dis[x]=dis[node]+1;
        q.push(x);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1,0);
  build();
  for(int i=1;i<=n;i++)dis[i]=inf;
  vector<int>tmp;
  tmp.push_back(1);
  while(m--)
  {
    cin>>t>>x;
    int ans=inf;
    if(t==1)
      tmp.push_back(x);
    else
    {
      ans=dis[x];
      for(int i=0;i<tmp.size();i++)
        ans=min(ans,query(tmp[i],x));
      cout<<ans<<endl;
    }
    if(tmp.size()>100)
    {
      while(tmp.size())
      {
        q.push(tmp.back());
        dis[tmp.back()]=0;
        tmp.pop_back();
      }
      upd();
    }
  }
  return 0;
}