/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2018 18:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 529 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/817/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e8;
const long N=1e6;
long n,arr[N+2],mn[N+2];
long mx[N+2],ans;
void divide(long lo,long hi)
{
  if(lo>=hi)return ;
  long md=(lo+hi)/2;
  divide(lo,md);divide(md+1,hi);
   long sum=0;
  mn[md+1]=arr[md+1];
  mx[md+1]=arr[md+1];
  for(long i=md+2;i<=hi;i++)
  {
    mn[i]=min(mn[i-1],arr[i]);
    mx[i]=max(mx[i-1],arr[i]);
    sum+=(mx[i]-mn[i])*1LL;
  }
  long mnp=md+1,mxp=md+1,nmn=inf,nmx=-inf;
  for(long i=md;i>=lo;i--)
  {
    if(arr[i]>nmx)
      sum+=(mxp-md-1)*(arr[i]-nmx);
    if(arr[i]<nmn)
      sum+=(mnp-md-1)*(nmn-arr[i]);
    nmn=min(nmn,arr[i]);
    nmx=max(nmx,arr[i]);
    while(true)
    {
      if(mxp>hi)break;
      if(nmx>mx[mxp])
      {
        sum+=(nmx-mx[mxp])*1LL;
        mxp++;
      }
      else break;
    }
    while(true)
    {
      if(mnp<lo)break;
      if(nmn<mn[mnp])
      {
        sum+=(mn[mnp]-nmn)*1LL;
        mnp++;
      }
      else break;
    }
    ans+=sum;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
   cin>>n;
  for(long i=1;i<=n;i++)
    cin>>arr[i];
  divide(1,n);
  cout<<ans<<endl;
  return 0;
}