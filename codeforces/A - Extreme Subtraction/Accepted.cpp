/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2020 21:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 1500 KB                              
*  problem: https://codeforces.com/contest/1442/problem/A
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
const int N=3e4;
int mn[4*N+8],lz[4*N+8],mx[4*N+8];
void tooLazy(int nd,int lo,int hi)
{
  mn[nd]+=lz[nd];mx[nd]+=lz[nd];
  if(lo!=hi)lz[nd*2]+=lz[nd],lz[nd*2+1]+=lz[nd];
  lz[nd]=0;
}
void upd(int nd,int lo,int hi,int lt,int rt,int ad)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[nd]+=ad;tooLazy(nd,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  upd(nd*2,lo,md,lt,rt,ad);upd(nd*2+1,md+1,hi,lt,rt,ad);
  mn[nd]=min(mn[nd*2],mn[nd*2+1]);
  mx[nd]=max(mx[nd*2],mx[nd*2+1]);
}
int getMin(int nd,int lo,int hi,int lt,int rt)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return 1e9;
  if(lo>=lt&&hi<=rt)return mn[nd];
  int md=(lo+hi)/2;
  return min(getMin(nd*2,lo,md,lt,rt),getMin(nd*2+1,md+1,hi,lt,rt));
}
int getMax(int nd,int lo,int hi,int lt,int rt)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return -1e9;
  if(lo>=lt&&hi<=rt)return mx[nd];
  int md=(lo+hi)/2;
  return max(getMax(nd*2,lo,md,lt,rt),getMax(nd*2+1,md+1,hi,lt,rt));
}
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=0;i<4*n+8;i++)mx[i]=0,mn[i]=0,lz[i]=0;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      upd(1,1,n,i,i,a[i]);
    }
    //for(int i=1;i<=n;i++)cout<<getMax(1,1,n,i,i)<<endl;
    int f=1;
    while(true)
    {
      int mn=getMin(1,1,n,1,n),lo,hi,md;
      if(mn<0){f=0;break;}
      if(getMax(1,1,n,1,n)==mn)break;
       lo=1,hi=n,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(getMin(1,1,n,1,md)>mn)lo=md;
        else hi=md;
      }
      for(md=lo;md<=hi;md++)if(getMin(1,1,n,1,md)==mn)break;
       int id=md;
      lo=id,hi=n,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(getMax(1,1,n,id,md)>mn)hi=md;
        else lo=md;
      }
      for(md=lo;md<=hi;md++)if(getMax(1,1,n,id,md)>mn)break;
       int g=getMax(1,1,n,id,md);
      if(g>mn)
      {
        upd(1,1,n,md,n,mn-g);continue;
      }
      g=getMin(1,1,n,id-1,id-1);
      upd(1,1,n,1,id-1,mn-g);
    }
    if(f)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}