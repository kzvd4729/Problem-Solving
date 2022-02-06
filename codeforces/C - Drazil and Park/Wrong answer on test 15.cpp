/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2020 22:45                        
*  solution_verdict: Wrong answer on test 15                 language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 13300 KB                             
*  problem: https://codeforces.com/contest/516/problem/C
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
const int N=1e5;
const long inf=1e18;
struct segment
{
  long lt,rt,mx,dsm;
}sg[4*N+8];
segment merge(segment a,segment b)
{
  segment c;
  c.lt=max(a.lt+b.dsm,b.lt);
  c.rt=max(a.rt,b.rt+a.dsm);
  c.dsm=a.dsm+b.dsm;
  c.mx=max({a.mx,b.mx,a.lt+b.rt});
  return c;
}
int d[N+2],h[N+2];
void build(int nd,int lo,int hi)
{
  if(lo==hi)
  {
    sg[nd]={2*h[lo]+d[lo],2*h[lo],0,d[lo]};
    return ;
  }
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
  sg[nd]=merge(sg[nd*2],sg[nd*2+1]);
}
segment get(int nd,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt||lt>rt)return {-inf,-inf,0,0};
  if(lo>=lt&&hi<=rt)return sg[nd];
  int md=(lo+hi)/2;
  segment a=get(nd*2,lo,md,lt,rt);
  segment b=get(nd*2+1,md+1,hi,lt,rt);
  return merge(a,b);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>d[i];
  for(int i=1;i<=n;i++)cin>>h[i];
   build(1,1,n);
  while(m--)
  {
    int l,r;cin>>l>>r;
    if(l<=r)
    {
      segment a=get(1,1,n,r+1,n);
      segment b=get(1,1,n,1,l-1);
      //cout<<a.lt<<" "<<a.rt<<" "<<a.dsm<<" "<<a.mx<<endl;
      cout<<merge(a,b).mx<<'\n';
    }
    else
    {
      cout<<get(1,1,n,r+1,l-1).mx<<'\n';
    }
  }
   return 0;
}