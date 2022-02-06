/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/15/2020 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 514 ms                                          memory_used: 105800 KB                            
*  problem: https://codeforces.com/contest/1304/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
  int lev[N+2],sp[N+2][21];
vector<int>adj[N+2];
void reckon(int n,int p,int h)
{
  sp[n][0]=p;lev[n]=h;
  for(auto x:adj[n])
    if(x!=p)reckon(x,n,h+1);
}
void sparse(int n)
{
  for(int j=1;j<=20;j++)
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
  int d=0;
  for(int i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=sp[u][i],d+=(1<<i);
  }
  if(u==v)return d;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i],v=sp[v][i];d+=2*(1<<i);
  }
  return d+2;
}
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  reckon(1,-1,0);sparse(n);
  int q;cin>>q;
  while(q--)
  {
    int x,y,a,b,k;cin>>x>>y>>a>>b>>k;
     int d1=lca(a,b);
    int d2=lca(a,x)+lca(b,y)+1;
    int d3=lca(a,y)+lca(b,x)+1;
     int f=0;
    if(k>=d1&&((k-d1)%2==0))f=1;
    if(k>=d2&&((k-d2)%2==0))f=1;
    if(k>=d3&&((k-d3)%2==0))f=1;
     //cout<<d1<<" "<<d2<<" "<<d3<<endl;
     if(f)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}