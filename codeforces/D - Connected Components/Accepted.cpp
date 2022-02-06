/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2020 18:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 840 ms                                          memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/292/problem/D
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int par[N+2];
int get(int x)
{
  if(x==par[x])return par[x];
  return par[x]=get(par[x]);
}
int u[N+2],v[N+2],a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)cin>>u[i]>>v[i];
   for(int i=1;i<=n;i++)par[i]=i;
  for(int i=1;i<=m;i++)
  {
    int p1=get(u[i]),p2=get(v[i]);
    if(p1==p2)continue;par[p1]=p2;
    a[i]=1;
  }
   for(int i=1;i<=n;i++)par[i]=i;
  for(int i=m;i>=1;i--)
  {
    int p1=get(u[i]),p2=get(v[i]);
    if(p1==p2)continue;par[p1]=p2;
    b[i]=1;
  }
   int q;cin>>q;
  while(q--)
  {
    int l,r;cin>>l>>r;int com=n;
    for(int i=1;i<=n;i++)par[i]=i;
     for(int i=1;i<l;i++)
    {
      if(a[i]==0)continue;
      int p1=get(u[i]),p2=get(v[i]);
      if(p1==p2)continue;par[p1]=p2;
      com--;
    }
    for(int i=m;i>r;i--)
    {
      if(b[i]==0)continue;
      int p1=get(u[i]),p2=get(v[i]);
      if(p1==p2)continue;par[p1]=p2;
      com--;
    }
    cout<<com<<'\n';
  }
   return 0;
}