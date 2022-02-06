/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2019 22:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/1165/problem/F2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],n,m,vis[N+2];
pair<int,int>of[N+2];
bool ok(int md)
{
  memset(vis,0,sizeof(vis));
  int lt=md;
  for(int i=m;i>=1;i--)
  {
    if(of[i].first>md)continue;
    int ty=of[i].second;
    lt=min(lt,of[i].first);
    int now=min(lt,aa[ty]-vis[ty]);
    lt-=now;vis[ty]+=now;
  }
  int cost=0;
  for(int i=1;i<=n;i++)
    cost+=vis[i]+(aa[i]-vis[i])*2;
  return cost<=md;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<=m;i++)
    cin>>of[i].first>>of[i].second;
  sort(of+1,of+m+1);
   int lo=1,hi=1e6,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ok(md))hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(ok(md))cout<<md<<endl,exit(0);
  return 0;
}