/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-11 18:36:06                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/arc091/tasks/arc091_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,d,r,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  if(k==0)
  {
    cout<<n*n<<endl;
    return 0;
  }
  for(long i=k+1;i<=n;i++)
  {
    d=n/i;
    r=n%i;
    ans+=((i-k)*d);
    if(r<k)continue;
    ans+=r-k+1;
  }
  cout<<ans<<endl;
  return 0;
}