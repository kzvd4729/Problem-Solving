/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/25/2020 11:12                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/659/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int a=-1,b=-1,c=-1,d=-1,e=-1,f=-1;
  int ans=aa[1]-1;a=2,b=aa[1],c=1;
  for(int i=2;i<=n;i++)
  {
    if(aa[i]>=aa[i-1])
    {
      int sm=0;
      if(a!=-1&&a<=b)sm=(sm+1LL*(b-a+1)*c)%mod;
      if(d!=-1&&d<=e)sm=(sm+1LL*(e-d+1)*f)%mod;
       sm++;ans=(ans+1LL*(aa[i-1]-1)*sm)%mod;
      a=2,b=aa[i],c=sm;
       ans=(ans+aa[i]-aa[i-1])%mod;
      d=aa[i-1]+1,e=aa[i],f=1;
    }
    else
    {
      int sm=0;
      b=min(b,aa[i]);e=min(e,aa[i]);
      if(a!=-1&&a<=b)sm=(sm+1LL*(b-a+1)*c)%mod;
      if(d!=-1&&d<=e)sm=(sm+1LL*(e-d+1)*f)%mod;
       sm++;ans=(ans+1LL*(aa[i]-1)*sm)%mod;
      d=-1;a=2,b=aa[i],c=sm;
    }
  }
  cout<<ans<<endl;
   return 0;
}