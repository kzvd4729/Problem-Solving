/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/22/2019 12:45                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1252/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long aa[N+2],bb[N+2];
long cal(long n,long md)
{
 long cnt=0;
 for(long i=1;i<=n;i++)
  if(bb[i]>=md)cnt++;
 if(cnt<2)return -inf;
  long mx1=0,mx2=0;
 for(long i=1;i<=n;i++)
 {
  if(aa[i]>=md)
  {
   if(bb[i]>=mx1){mx2=mx1;mx1=bb[i];}
   else mx2=max(mx2,bb[i]);
  }
  else if(bb[i]>=md)
  {
   if(aa[i]>=mx1){mx2=mx1;mx1=aa[i];}
   else mx2=max(mx2,aa[i]); 
  }
 }
 //cout<<md<<" ----- "<<mx2<<endl;
 return 1LL*md*mx2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;long mx=0;
  for(long i=1;i<=n;i++)
  {
   cin>>aa[i]>>bb[i];
   if(aa[i]>bb[i])swap(aa[i],bb[i]);
   mx=max(mx,1LL*aa[i]*bb[i]);
   //cout<<aa[i]<<" --> "<<bb[i]<<endl;
  }
  long lo=0,hi=1e9,md1,md2;
   while(hi-lo>2)
  {
   md1=(lo+lo+hi)/3,md2=(lo+hi+hi)/3;
   if(cal(n,md1)>=cal(n,md2))hi=md2;
   else lo=md1;
  }
  //cout<<lo<<" ** "<<hi<<endl;
  for(long md=lo;md<=hi;md++)
   mx=max(mx,2*cal(n,md));
  cout<<setprecision(1)<<fixed<<(mx/2.0)<<endl;
    return 0;
}