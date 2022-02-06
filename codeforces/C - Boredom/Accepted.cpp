/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/20/2020 14:22                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1294 ms                                         memory_used: 34600 KB                             
*  problem: https://codeforces.com/contest/853/problem/C
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
const int N=2e5;
int a[N+2],l[N+2],r[N+2],d[N+2],u[N+2],n,q;
long ans[N+2];
vector<int>seg[4*N+8];
void build(int nd,int lo,int hi)
{
  if(lo==hi){seg[nd].push_back(a[lo]);return;}
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
   seg[nd].resize((int)seg[nd*2].size()+(int)seg[nd*2+1].size());
  merge(seg[nd*2].begin(),seg[nd*2].end(),seg[nd*2+1].begin(),seg[nd*2+1].end(),seg[nd].begin());
}
int get(int nd,int lo,int hi,int lt,int rt,int x,int y)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)
    return upper_bound(seg[nd].begin(),seg[nd].end(),y)-lower_bound(seg[nd].begin(),seg[nd].end(),x);
   int md=(lo+hi)/2;
  return get(nd*2,lo,md,lt,rt,x,y)+get(nd*2+1,md+1,hi,lt,rt,x,y);
}
void solve1()
{
  for(int i=1;i<=q;i++)
  {
    int rm=l[i]-1;
    ans[i]-=(1LL*rm*(rm-1))/2;
  }
  for(int i=1;i<=q;i++)
  {
    int rm=n-r[i];
    ans[i]-=(1LL*rm*(rm-1))/2;
  }
  for(int i=1;i<=q;i++)
  {
    int rm=d[i]-1;
    ans[i]-=(1LL*rm*(rm-1))/2;
  }
  for(int i=1;i<=q;i++)
  {
    int rm=n-u[i];
    ans[i]-=(1LL*rm*(rm-1))/2;
  }
}
void solve2()
{
  build(1,1,n);
  for(int i=1;i<=q;i++)
  {
    int rm;
     rm=0;
    if(l[i]-1&&d[i]-1)rm=get(1,1,n,1,l[i]-1,1,d[i]-1);
    ans[i]+=(1LL*rm*(rm-1))/2;
     rm=0;
    if(r[i]+1<=n&&d[i]-1)rm=get(1,1,n,r[i]+1,n,1,d[i]-1);
    ans[i]+=(1LL*rm*(rm-1))/2;
     rm=0;
    if(l[i]-1&&u[i]+1<=n)rm=get(1,1,n,1,l[i]-1,u[i]+1,n);
    ans[i]+=(1LL*rm*(rm-1))/2;
     rm=0;
    if(r[i]+1<=n&&u[i]+1<=n)rm=get(1,1,n,r[i]+1,n,u[i]+1,n);
    ans[i]+=(1LL*rm*(rm-1))/2;
   }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=q;i++)cin>>l[i]>>d[i]>>r[i]>>u[i];
   long tt=(1LL*n*(n-1))/2;
  for(int i=1;i<=q;i++)ans[i]=tt;
   solve1();solve2();
  for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
   return 0;
}