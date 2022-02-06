/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2020 22:41                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 13300 KB                             
*  problem: https://codeforces.com/contest/1439/problem/C
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
int a[N+2],mn[4*N+8],lz[4*N+8];long sm[4*N+8];
void build(int nd,int lo,int hi)
{
  if(lo==hi)
  {
    sm[nd]=a[lo],mn[nd]=a[lo];return ;
  }
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
  sm[nd]=sm[nd*2]+sm[nd*2+1],mn[nd]=min(mn[nd*2],mn[nd*2+1]);
}
void tooLazy(int nd,int lo,int hi)
{
  if(lz[nd]==0)return ;
  sm[nd]=(hi-lo+1)*lz[nd],mn[nd]=lz[nd];
   if(lo!=hi)lz[nd*2]=lz[nd],lz[nd*2+1]=lz[nd];
  lz[nd]=0;
}
void assign(int nd,int lo,int hi,int lt,int rt,int vl)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[nd]=vl;tooLazy(nd,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  assign(nd*2,lo,md,lt,rt,vl);assign(nd*2+1,md+1,hi,lt,rt,vl);
  sm[nd]=sm[nd*2]+sm[nd*2+1],mn[nd]=min(mn[nd*2],mn[nd*2+1]);
}
int small(int nd,int lo,int hi,int id,int vl)
{
  tooLazy(nd,lo,hi);
  if(lo==hi)
  {
    if(mn[nd]<=vl)return lo;
    else return N+1;
  }
  int md=(lo+hi)/2;
  if(md>=id&&mn[nd*2]<=vl)return small(nd*2,lo,md,id,vl);
  else return small(nd*2+1,md+1,hi,id,vl);
}
int ans;
int now(int nd,int lo,int hi,int id,int vl)
{
  tooLazy(nd,lo,hi);
  if(hi<id||mn[nd]>vl)return vl;
  if(lo>=id&&sm[nd]<=vl)
  {
    ans+=hi-lo+1;
    return vl-sm[nd];
  }
  int md=(lo+hi)/2;
  vl=now(nd*2,lo,md,id,vl);
  return now(nd*2+1,md+1,hi,id,vl); 
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i];
  build(1,1,n);
    while(q--)
  {
    int ty,x,y;cin>>ty>>x>>y;
    if(ty==1)
    {
      int id=small(1,1,n,1,y);
      if(id<=x)assign(1,1,n,id,x,y);
    }
    else
    {
      ans=0;
      now(1,1,n,x,y);cout<<ans<<'\n';
    }
  }
    return 0;
}