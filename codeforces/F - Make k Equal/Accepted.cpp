/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2020 19:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 5500 KB                              
*  problem: https://codeforces.com/contest/1328/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],bf[N+2],af[N+2];long pr[N+2],sf[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1);
   for(int i=1;i<=n;i++)pr[i]=pr[i-1]+aa[i];
  for(int i=n;i>=1;i--)sf[i]=sf[i+1]+aa[i];
   bf[1]=0;
  for(int i=2;i<=n;i++)
  {
    if(aa[i]==aa[i-1])bf[i]=bf[i-1];
    else bf[i]=i-1;
  }
  af[n]=n+1;
  for(int i=n;i>=1;i--)
  {
    if(aa[i]==aa[i+1])af[i]=af[i+1];
    else af[i]=i+1;
  }
  //for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<endl;
  long ans=1e18;
  for(int i=1;i<=n;i++)
  {
    int b=bf[i],a=af[i];
    int now=n-(b+n-a+1);
    if(now>=k)cout<<0<<endl,exit(0);
     long cs1=1LL*(aa[i]-1)*b-pr[b];
    long cs2=sf[a]-1LL*(aa[i]+1)*(n-a+1);
     //cout<<cs1<<" "<<cs2<<endl;
     if(b+now>=k)ans=min(ans,cs1+k-now);
    if(n-a+1+now>=k)ans=min(ans,cs2+k-now);
     ans=min(ans,cs1+cs2+k-now);
  }
  cout<<ans<<endl;
  return 0;
}