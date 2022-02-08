/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-24 17:53:43                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 34 ms                                           memory_used: 6256 KB                              
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
  sort(v.begin(),v.end(),greater<long>());
  long sum=(1LL<<62)-1;
  for(int i=0;i<k;i++)
    sum&=v[i];
  cout<<sum<<endl;
  return 0;
}