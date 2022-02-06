/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/17/2020 16:55                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 27900 KB                             
*  problem: https://codeforces.com/contest/855/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
vector<int>adj[N+2],ty[N+2];
int sp[N+2],pr[N+2],ent[N+2],ext[N+2],tim,ln[N+2];
void dfs(int node,int ds,int l,int d)
{
  ent[node]=++tim;ln[node]=d;
  if(l==0)sp[node]=ds;else if(l==1)pr[node]=ds;
  for(int i=0;i<adj[node].size();i++)
    dfs(adj[node][i],ty[node][i]==l?ds+1:1,ty[node][i],d+1);
  ext[node]=tim;
}
int lev[N+2],spr[N+2][21];
void reckon(int n,int p,int h)
{
  spr[n][0]=p;lev[n]=h;
  for(auto x:adj[n])
    if(x!=p)reckon(x,n,h+1);
}
void sparse(int n)
{
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      spr[i][j]=spr[i][j-1];
      if(spr[i][j-1]!=-1)
        spr[i][j]=spr[spr[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  for(int i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=spr[u][i];
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(spr[u][i]==spr[v][i])continue;
    u=spr[u][i],v=spr[v][i];
  }
  return spr[u][0];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int rt;
  for(int i=1;i<=n;i++)
  {
    int u,v;cin>>u>>v;
    if(u==-1){rt=i;continue;}
    adj[u].push_back(i);ty[u].push_back(v);
  }
  memset(sp,-1,sizeof(sp));memset(pr,-1,sizeof(pr));
  dfs(rt,0,-1,0);reckon(rt,-1,0);sparse(n);
  //for(int i=1;i<=n;i++)cout<<sp[i]<<" ** ";cout<<endl;
  int q;cin>>q;
  while(q--)
  {
    int t,u,v;cin>>t>>u>>v;
    if(u==v){cout<<"NO\n";continue;}
    if(t==1)
    {
      if(ent[v]>=ent[u]&&ent[v]<=ext[u]&&ln[v]-ln[u]<=sp[v])cout<<"YES\n";
      else cout<<"NO\n";
    }
    else
    {
      int lc=lca(u,v);
      if(lc==u)
      {
        if(ln[v]-ln[u]<=pr[v])cout<<"YES\n";else cout<<"NO";
      }
      else
      {
        if(ln[v]-ln[lc]<=pr[v]&&ln[u]-ln[lc]<=sp[u])cout<<"YES\n";
        else cout<<"NO\n";
      }
    }
  }
  return 0;
}