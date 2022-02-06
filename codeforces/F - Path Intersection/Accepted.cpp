/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2019 20:03                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 935 ms                                          memory_used: 13500 KB                             
*  problem: https://codeforces.com/gym/102040/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
bitset<N+2>bt[N+2],ans;
 int lev[N+2],sp[N+2][15];
vector<int>adj[N+2];
void reckon(int n,int p,int h)
{
  sp[n][0]=p,lev[n]=h,bt[n]=bt[p];bt[n][n]=1;
  for(auto x:adj[n])
    if(x!=p)reckon(x,n,h+1);
}
void sparse(int n)
{
  for(int j=1;j<=14;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(sp[i][j-1]!=-1)
        sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  for(int i=14;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=14;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i],v=sp[v][i];
  }
  return sp[u][0];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    reckon(1,0,0);sparse(n);
     int q;cin>>q;cout<<"Case "<<++tc<<":\n";
    while(q--)
    {
      int k;cin>>k;ans.set();
      while(k--)
      {
        int u,v;cin>>u>>v;
        int l=lca(u,v);
         ans&=((bt[u]^bt[sp[l][0]])|(bt[v]^bt[sp[l][0]]));
      }
      cout<<ans.count()<<"\n";
    }
  }
  return 0;
}