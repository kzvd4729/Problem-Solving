/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/13/2019 15:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1244/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
   long l=1,r=n,a=aa[1],b=aa[n],c1=1,c2=1;
  while(true)
  {
    if(a>=b)cout<<0<<endl,exit(0);
    while(l<n)
    {
      if(aa[l+1]==a)l++,c1++;
      else break;
    }
    while(r>1)
    {
      if(aa[r-1]==b)r--,c2++;
      else break;
    }
    if((k/min(c1,c2))==0)cout<<b-a<<endl,exit(0);
    if(c1<c2)
    {
      long mn=min(aa[l+1]-a,k/c1);
      a+=mn;k-=mn*c1;
    }
    else
    {
      long mn=min(b-aa[r-1],k/c2);
      b-=mn;k-=mn*c2;
    }
  }
  return 0;
}