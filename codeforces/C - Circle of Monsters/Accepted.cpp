/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2020 16:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 31300 KB                             
*  problem: https://codeforces.com/contest/1334/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],bb[N+2],pre[N+2],suf[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    for(int i=0;i<=n+1;i++)
      aa[i]=0,bb[i]=0,pre[i]=0,suf[i]=0;
    for(long i=1;i<=n;i++)cin>>aa[i]>>bb[i];
     for(long i=2;i<=n;i++)
      pre[i]=pre[i-1]+max(0LL,aa[i]-bb[i-1]);
    for(long i=n-1;i>=1;i--)
      suf[i]=suf[i+1]+max(0LL,aa[i+1]-bb[i]);
     // for(long i=1;i<=n;i++)cout<<suf[i]<<" ";
    //   cout<<endl;
    long ans=aa[1]+suf[1];
    for(long i=2;i<=n;i++)
      ans=min(ans,aa[i]+suf[i]+max(0LL,aa[1]-bb[n])+pre[i-1]);
    cout<<ans<<"\n";
  }
  return 0;
}