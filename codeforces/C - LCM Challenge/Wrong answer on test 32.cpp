/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2018 10:31                        
*  solution_verdict: Wrong answer on test 32                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/236/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ans,tw,n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
   tw=n*(max(n-1LL,1LL));
   for(int i=1;i<=n;i++)
    ans=max(ans,(tw*i*1LL)/__gcd(tw,i*1LL));
  cout<<ans<<endl;
   return 0;
}