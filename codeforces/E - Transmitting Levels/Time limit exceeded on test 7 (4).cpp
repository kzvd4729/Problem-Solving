/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/18/2020 13:26                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/526/problem/E
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
#include<stack>
#include<deque>
#define long long long
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
const int N=2e6;
int aa[N+2],n;
int brut(int st,long x)
{
  int ed=st+n-1,rt=1;long now=0;
  for(int i=st;i<=ed;i++)
  {
    if(now+aa[i]>x)rt++,now=aa[i];
    else now+=aa[i];
  }
  return rt;
}
long qm[N+2];
int jump(int st,long x)
{
  int ed=st+n-1,rt=0;
  while(st<=ed)
  {
    int lo=st,hi=ed,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(qm[md]-qm[st-1]<=x)lo=md;
      else hi=md;
    }
    for(md=hi;md>=lo;md--)
      if(qm[md]-qm[st-1]<=x)break;
    st=md+1;rt++;
  }
  return rt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>aa[i],aa[n+i]=aa[i];
  for(int i=1;i<=n+n;i++)qm[i]=qm[i-1]+aa[i];
  while(q--)
  {
    long x;cin>>x;long cur=0;int l=1,mx=1e9,a=1,b=n;
    for(int i=1;i<=n+n;i++)
    {
      cur+=aa[i];
      if(cur>x)
      {
        if(i-l+1<mx)mx=i-l+1,a=l,b=i;
        while(cur>x)cur-=aa[l++];
      }
    }
    int mn=1e9;//if(a>1)a--;if(b<n+n)b++;
    if(b-a+1<=20)
    {
      for(int i=a;i<=b;i++)mn=min(mn,brut(i,x));
      cout<<mn<<"\n";
    }
    else
    {
      for(int i=a;i<=b;i++)mn=min(mn,jump(i,x));
      cout<<mn<<"\n";
    }
  }
  return 0;
}