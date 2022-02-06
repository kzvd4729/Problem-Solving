/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/13/2019 20:28                        
*  solution_verdict: Time limit exceeded on test 33          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 65200 KB                             
*  problem: https://codeforces.com/contest/571/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int a,b,lft[N+2],rgt[N+2],dis[N+2];
int adj[N+2][2],pt[N+2],q[N+2];
bool bfs(void)
{
  int sz=0;
  for(int i=1;i<=a;i++)
  {
    if(!lft[i])q[sz++]=i,dis[i]=0;
    else dis[i]=inf;
  }
  dis[0]=inf;
  for(int p=0;p<sz;p++)
  {
    int u=q[p];
    for(int i=0;i<pt[u];i++)
    {
      int v=adj[u][i];
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
  for(int i=0;i<pt[u];i++)
  {
    int v=adj[u][i];
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
int hopcroft(void)
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
int bin[N+2],vis[N+2];
vector<int>pos[N+2],neg[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int k;cin>>k;
    while(k--)
    {
      int x;cin>>x;
      if(x>0)pos[x].push_back(i);
      else neg[-x].push_back(i);
    }
  }
  for(int i=1;i<=m;i++)
  {
    if(pos[i].size()==0&&neg[i].size()==0)continue;
    if(pos[i].size()==0)
    {
      for(auto x:neg[i])vis[x]=1;
      bin[i]=0;continue;
    }
    if(neg[i].size()==0)
    {
      for(auto x:pos[i])vis[x]=1;
      bin[i]=1;continue;
    }
  }
  for(int i=1;i<=m;i++)
  {
    if(pos[i].size()==0||neg[i].size()==0)continue;
    if(!vis[pos[i][0]])adj[i][pt[i]++]=pos[i][0];
    if(!vis[neg[i][0]])adj[i][pt[i]++]=neg[i][0];
  }
  int cnt=0;
  for(int i=1;i<=n;i++)cnt+=vis[i];
  a=m,b=n;
  if(cnt+hopcroft()==n)
  {
    cout<<"YES\n";
    for(int i=1;i<=m;i++)
    {
      if(lft[i])
      {
        if(lft[i]==pos[i][0])bin[i]=1;
        else bin[i]=0;
      }
      cout<<bin[i];
    }
    cout<<"\n";
  }
  else cout<<"NO\n";
   return 0;
}