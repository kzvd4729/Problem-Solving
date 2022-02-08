/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-01 19:27:29                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 36 ms                                           memory_used: 1024 KB                              
*  problem: https://atcoder.jp/contests/arc102/tasks/arc102_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,k,cnt[N+2],ans;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(long i=1;i<=n;i++)
    cnt[i%k]++;
  for(long i=1;i<=n;i++)
  {
    long r1=(k-(i%k))%k;
    long r2=(k-(r1%k))%k;
    if(r1==r2)ans+=cnt[r1]*cnt[r2];
  }
  cout<<ans<<endl;
  return 0;
}