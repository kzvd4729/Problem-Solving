/****************************************************************************************
*  @author: kzvd4729                                         created: May/24/2020 19:17                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 31600 KB                             
*  problem: https://codeforces.com/contest/472/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=2e3;
int mt[N+2][N+2],vs[N+2][N+2],ok[N+2];
vector<pair<int,int> >adj[N+2];
void no()
{
  cout<<"NO\n"<<endl,exit(0);
}
void dfs(int node,int par,int bg,int ds)
{
  //cout<<node<<" "<<mt[bg][node]<<" "<<ds<<endl;
  if(mt[bg][node]!=ds)no();
  if(ok[node])no();ok[node]=1;
  for(auto x:adj[node])
    if(x.first!=par)dfs(x.first,node,bg,ds+x.second);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      int x;cin>>x;
      if(i==j&&x)no();if(i!=j&&x==0)no();
      mt[i][j]=x;
    }
  }
  for(int i=1;i<=n;i++)
  {
    int mn=2e9,id=0;
    for(int j=1;j<=n;j++)
    {
      if(i==j)continue;
      if(mt[i][j]<mn)mn=mt[i][j],id=j;
    }
    if(id==0)continue;
    if(vs[i][id]==0)
    {
      adj[i].push_back({id,mn});
      adj[id].push_back({i,mn});
      vs[i][id]=1,vs[id][i]=1;
      //cout<<i<<" "<<id<<" "<<mn<<endl;
    }
    int nx=0,an=2e9;
    for(int j=1;j<=n;j++)
    {
      if(i==j||j==id)continue;
      if(mt[i][j]<an)an=mt[i][j],nx=j;
    }
    if(nx==0)continue;
    if(mt[id][nx]==mn+an&&vs[i][nx]==0)
    {
      adj[i].push_back({nx,an});
      adj[nx].push_back({i,an});
      vs[i][nx]=1,vs[nx][i]=1;
      //cout<<i<<" "<<nx<<" "<<an<<endl;
    }
    else if(vs[id][nx]==0)
    {
      adj[id].push_back({nx,an-mn});
      adj[nx].push_back({id,an-mn});
      vs[id][nx]=1,vs[nx][id]=1;
      //cout<<id<<" "<<nx<<" "<<an-mn<<endl;
    }
  }
  for(int i=1;i<=n;i++)
  {
    memset(ok,0,sizeof ok);
    dfs(i,-1,i,0);
    for(int j=1;j<=n;j++)if(ok[i]==0)no();
  }
  cout<<"YES\n";
  return 0;
}