/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/03/2018 22:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 14100 KB                             
*  problem: https://codeforces.com/contest/1016/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e5;
long a[N+2],b[N+2],n,cnt1,cnt2;
long uqm[N+2],dqm[N+2],ans,here;
long usum[N+2],dsum[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)
    cin>>a[i];
  for(long i=1;i<=n;i++)
    cin>>b[i];
   cnt1=n*2-2;
  cnt2=n*2-1;
  for(int i=n;i>=1;i--)
  {
    uqm[i]=uqm[i+1]+a[i]*cnt1+b[i]*cnt2-usum[i+1];
    usum[i]+=usum[i+1]+a[i]+b[i];
    cnt1-=2;
  }
  cnt1=n*2-1;
  cnt2=n*2-2;
  for(int i=n;i>=1;i--)
  {
    dqm[i]=dqm[i+1]+a[i]*cnt1+b[i]*cnt2-dsum[i+1];
    dsum[i]+=dsum[i+1]+a[i]+b[i];
    cnt2-=2;
  }
    ans=0;
  long sum=0,cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(i%2)ans=max(ans,sum+uqm[i]);
    else ans=max(ans,sum+dqm[i]);
     if(i%2)
    {
      sum+=(cnt*a[i]);
      cnt++;
      sum+=(cnt*b[i]);
      cnt++;
    }
    else
    {
      sum+=(cnt*b[i]);
      cnt++;
      sum+=(cnt*a[i]);
      cnt++;
    }
  }
  cout<<ans<<endl;
  return 0;
}