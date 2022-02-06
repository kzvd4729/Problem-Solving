/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/16/2020 01:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 686 ms                                          memory_used: 27500 KB                             
*  problem: https://codeforces.com/contest/1304/problem/E
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 const int N = 2e5 + 7;
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
int dist(int u,int v)
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
 int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    reckon(1,0,0);sparse(n);
    int q; cin >> q;
    while(q--) {
        int x, y, a, b, k, f = 0; cin >> x >> y >> a >> b >> k;
        int d1 = dist(a, b);
        if(d1 <= k && (k - d1) % 2 == 0) f = 1;
        int d2 = dist(a, x) + dist(b, y) + 1;
        if(d2 <= k && (k - d2) % 2 == 0) f = 1;
        int d3 = dist(a, y) + dist(b, x) + 1;
        if(d3 <= k && (k - d3) % 2 == 0) f = 1;
        if(f) cout << "YES" << endl;
        else  cout << "NO" << endl;
    }
}