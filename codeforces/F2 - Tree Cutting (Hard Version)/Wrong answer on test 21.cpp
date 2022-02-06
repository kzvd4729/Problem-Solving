/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/21/2019 20:19                        
*  solution_verdict: Wrong answer on test 21                 language: GNU C++14                               
*  run_time: 451 ms                                          memory_used: 64700 KB                             
*  problem: https://codeforces.com/contest/1118/problem/F2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
/**************** LCA ********************/
int Par[N+2],Lev[N+2],Sp[N+2][22];
vector<int>Adj[N+2];
void Reckon(int n,int p,int h)
{
  Par[n]=p;Lev[n]=h;
  for(auto x:Adj[n])
    if(x!=p)Reckon(x,n,h+1);
}
void Build_Sparse(int n)
{
  memset(Sp,-1,sizeof(Sp));
  for(int i=1;i<=n;i++)
    Sp[i][0]=Par[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(Sp[i][j-1]==-1)continue;
      Sp[i][j]=Sp[Sp[i][j-1]][j-1];
    }
  }
}
int Lca(int u,int v)
{
  if(Lev[u]<Lev[v])swap(u,v);int d=0;
  for(int i=20;i>=0;i--)
  {
    if(Lev[u]-(1<<i)>=Lev[v])
      u=Sp[u][i],d+=(1<<i);
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(Sp[u][i]==-1||Sp[v][i]==-1)continue;
    if(Sp[u][i]==Sp[v][i])continue;
    u=Sp[u][i];v=Sp[v][i];d+=2*(1<<i);
  }
  d+=2;return Par[u];
}
//////////////////////////////////////////
int cl[N+2];
vector<int>col[N+2];
void color(int u,int lc,int c)
{
  u=Par[u];if(u==-1)return ;
  while(Lev[u]>=Lev[lc])
  {
    if(cl[u]==0)cl[u]=c;
    else 
    {
      if(cl[u]==c)return ;
      cout<<0<<endl,exit(0);
    }
    u=Par[u];if(u==-1)return ;
  }
}
void color2(int u,int c)
{
  while(u!=-1)
  {
    if(cl[u]==0)cl[u]=c;
    else return ;
    u=Par[u];
  }
}
int cnt=0;
void dfs(int n)
{
  cnt++;cl[n]=1;
  for(auto x:Adj[n])
  {
    if(cl[x])continue;
    dfs(x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;if(n==2)cout<<1<<endl,exit(0);
  for(int i=1;i<=n;i++)
  {
    cin>>cl[i];col[cl[i]].push_back(i);
  }
  int rt=-1;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
    if(Adj[u].size()>1)rt=u;
    if(Adj[v].size()>1)rt=v;
  }
  Reckon(rt,-1,0);Build_Sparse(n);
  for(int i=1;i<=k;i++)
  {
    if(col[i].size()>1)
    {
      int lc=Lca(col[i][0],col[i][1]);
      color(col[i][0],lc,i);
      color(col[i][1],lc,i);
      for(int j=2;j<col[i].size();j++)
      {
        int lcc=Lca(lc,col[i][j]);
        color(lc,lcc,i);
        color(col[i][j],lcc,i);
        lc=lcc;
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    if(Adj[i].size()==1&&cl[i]==0)
    {
      color2(i,k+1);
    }
  }
  vector<int>v;
  for(int i=1;i<=n;i++)
  {
    if(cl[i]==0)
    {
      cnt=0;dfs(i);
      v.push_back(cnt+1);
    }
  }
  long ans=1,mod=998244353;
  for(auto x:v)
    ans=(ans*x)%mod;
  cout<<ans<<endl;
  return 0;
}