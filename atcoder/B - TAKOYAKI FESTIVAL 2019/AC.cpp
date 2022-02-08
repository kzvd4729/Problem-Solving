/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-19 18:05:54                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc143/tasks/abc143_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      ans+=aa[i]*aa[j];
    }
  }
  cout<<ans<<endl;
  return 0;
}