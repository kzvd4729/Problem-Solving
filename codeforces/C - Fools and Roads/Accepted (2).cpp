/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/04/2019 10:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 623 ms                                          memory_used: 24100 KB                             
*  problem: https://codeforces.com/contest/191/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int cnt[100005],ans[100005],n,u,v,q;
map<pair<int,int>,int>mp;
 /**************** LCA ********************/
int Par[N+2],Lev[N+2];vector<int>Adj[N+2];
int Sp[N+2][22];
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
  if(Lev[u]<Lev[v])swap(u,v);
  for(int i=20;i>=0;i--)
  {
    if(Lev[u]-(1<<i)>=Lev[v])
      u=Sp[u][i];
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(Sp[u][i]==-1||Sp[v][i]==-1)continue;
    if(Sp[u][i]==Sp[v][i])continue;
    u=Sp[u][i];v=Sp[v][i];
  }
  return Par[u];
}
//////////////////////////////////////////
 void dfs(int n,int p)
{
    for(auto x:Adj[n])
    {
        if(x==p)continue;
        dfs(x,n);cnt[n]+=cnt[x];
        int k=mp[make_pair(min(n,x),max(n,x))];
        ans[k]=cnt[x];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        Adj[u].push_back(v);Adj[v].push_back(u);
        mp[make_pair(min(u,v),max(u,v))]=i;
     }
    Reckon(1,-1,0);
    Build_Sparse(n);
    cin>>q;
    while(q--)
    {
        cin>>u>>v;int lc=Lca(u,v);
        cnt[u]++;cnt[lc]--;
        cnt[v]++;cnt[lc]--;
    }
    dfs(1,-1);
    for(int i=1;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}