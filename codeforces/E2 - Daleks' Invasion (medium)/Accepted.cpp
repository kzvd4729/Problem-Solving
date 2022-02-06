/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 16:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2994 ms                                         memory_used: 78500 KB                             
*  problem: https://codeforces.com/contest/1184/problem/E2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int par[N+2],n,pcst[N+2];
vector<pair<int,pair<int,int> > >v;
pair<int,pair<int,int> >p;
int _find(int x)
{
  if(x==par[x])return x;
  return par[x]=_find(par[x]);
}
/**************** LCA ********************/
int Par[N+2],Lev[N+2],Sp[N+2][22],sp[N+2][22];
vector<int>Adj[N+2],cst[N+2];
void Reckon(int n,int p,int h,int cs)
{
  Par[n]=p;Lev[n]=h;pcst[n]=cs;
  for(int i=0;i<Adj[n].size();i++)
  {
    int x=Adj[n][i];
    if(x!=p)Reckon(x,n,h+1,cst[n][i]);
  }
}
void Build_Sparse(void)
{
  memset(Sp,-1,sizeof(Sp));
  for(int i=1;i<=n;i++)
  {
    Sp[i][0]=Par[i];
    sp[i][0]=pcst[i];
  }
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(Sp[i][j-1]==-1)continue;
      Sp[i][j]=Sp[Sp[i][j-1]][j-1];
      sp[i][j]=max(sp[i][j],sp[Sp[i][j-1]][j-1]);
    }
  }
}
int Lca(int u,int v)
{
  if(Lev[u]<Lev[v])swap(u,v);int d=0,mx=0;
  for(int i=20;i>=0;i--)
  {
    if(Lev[u]-(1<<i)>=Lev[v])
    {
      mx=max(mx,sp[u][i]);
      u=Sp[u][i];
    }
  }
  if(u==v)return mx;
  for(int i=20;i>=0;i--)
  {
    if(Sp[u][i]==-1||Sp[v][i]==-1)continue;
    if(Sp[u][i]==Sp[v][i])continue;
    mx=max(mx,sp[u][i]);mx=max(mx,sp[v][i]);
    u=Sp[u][i];v=Sp[v][i];
  }
  mx=max(mx,pcst[u]);
  mx=max(mx,pcst[v]);
  return mx;
}
//////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;vector<pair<int,int> >edge;
  for(int i=1;i<=m;i++)
  {
    int a,b,c;cin>>a>>b>>c;
    v.push_back({c,{a,b}});
    edge.push_back({a,b});
  }
  sort(v.begin(),v.end());
  for(int i=1;i<=n;i++)par[i]=i;
  set<pair<int,int> >st;
  for(auto x:v)
  {
    int r1=_find(x.second.first);
    int r2=_find(x.second.second);
    if(r1==r2){st.insert(x.second);continue;}
    par[r1]=r2;
    Adj[x.second.first].push_back(x.second.second);
    cst[x.second.first].push_back(x.first);
    Adj[x.second.second].push_back(x.second.first);
    cst[x.second.second].push_back(x.first);
  }
  Reckon(1,-1,0,0);Build_Sparse();
  for(auto x:edge)
  {
    if(st.find(x)==st.end())continue;
    cout<<Lca(x.first,x.second)<<"\n";
  }
  return 0;
}