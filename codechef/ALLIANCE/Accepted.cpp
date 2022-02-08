/****************************************************************************************
*  @author: kzvd4729                                         created: 03-03-2019 23:51:26                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.20 sec                                        memory_used: 140.1M                               
*  problem: https://www.codechef.com/problems/ALLIANCE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
vector<int>vv[N+2];
int gg[N+2];
int Par[N+2],Lev[N+2],Sp[N+2][22];
int Tim,Ent[N+2],Ext[N+2];
vector<int>Adj[N+2];
void Reckon(int n,int p,int h)
{
  Par[n]=p;Lev[n]=h;Ent[n]=++Tim;
  for(auto x:Adj[n])
    if(x!=p)Reckon(x,n,h+1);
  Ext[n]=Tim;
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
int Lca(int u,int v,int &d)
{
  if(Lev[u]<Lev[v])swap(u,v);d=0;
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }
  Reckon(1,-1,0);Build_Sparse(n);
  int k,d;cin>>k;
  for(int i=1;i<=k;i++)
  {
    int x;cin>>x;
    for(int j=1;j<=x;j++)
    {
      int z;cin>>z;vv[i].push_back(Ent[z]);
      if(j==1)gg[i]=z;
      else gg[i]=Lca(gg[i],z,d);
    }
    sort(vv[i].begin(),vv[i].end());
  }
  int q;cin>>q;
  while(q--)
  {
    int cp;cin>>cp;
    int x;cin>>x;int lc;vector<int>v;
    for(int j=1;j<=x;j++)
    {
      int z;cin>>z;v.push_back(z);
      if(j==1)lc=gg[z];
      else lc=Lca(lc,gg[z],d);
    }
    if(Ent[lc]>=Ent[cp]&&Ent[lc]<=Ext[cp])
    {
      cout<<Lev[lc]-Lev[cp]<<"\n";
      continue;
    }
    int f=0;
    for(auto z:v)
    {
      int id=lower_bound(vv[z].begin(),vv[z].end(),Ent[cp])-vv[z].begin();
      if(id>=vv[z].size())continue;
      if(vv[z][id]<=Ext[cp])f=1;
    }
    if(f)
    {
      cout<<0<<"\n";continue;
    }
    int ans=Lev[cp]+Lev[lc];
    for(auto x:v)
    {
      int u=cp;int now;
      for(int i=20;i>=0;i--)
      {
        if(Sp[u][i]==-1)continue;int uu=Sp[u][i];
        int id=lower_bound(vv[x].begin(),vv[x].end(),Ent[uu])-vv[x].begin();
        if(id>=vv[x].size())
        {
          u=uu;continue;
        }
        if(vv[x][id]<=Ext[uu])continue;
        u=Sp[u][i];
      }
      u=Par[u];if(u==-1)assert(0);
      if(Ent[lc]>=Ent[u]&&Ent[lc]<=Ext[u])
        ans=min(ans,Lev[cp]-Lev[u]+Lev[lc]-Lev[u]);
      else ans=min(ans,Lev[cp]-Lev[u]);
    }
    cout<<ans<<"\n";
  }
  return 0;
}