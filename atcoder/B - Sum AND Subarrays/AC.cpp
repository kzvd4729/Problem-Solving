/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-24 18:02:23                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 19 ms                                           memory_used: 6384 KB                              
*  problem: https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long n,k,aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;vector<long>v;
  for(long i=1;i<=n;i++)
    cin>>aa[i];
  for(long i=1;i<=n;i++)
  {
    long sum=0;
    for(long j=i;j<=n;j++)
    {
      sum+=(aa[j]*1LL);
      v.push_back(sum);
    }
  }
  long ans=0;vector<long>tmp;
  for(long i=62;i>=0;i--)
  {
    tmp.clear();
    for(auto x:v)
    {
      if(x&(1LL<<i))
      {
        tmp.push_back(x);
      }
    }
    if(tmp.size()>=k)
    {
      ans|=(1LL<<i);v=tmp;
    }
  }
  cout<<ans<<endl;
  return 0;
}