/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2018 18:47                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/732/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c,ans,mx;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>b>>c;
  mx=max(a,max(b,c));
  ans+=max(0LL,mx-a-1);
  ans+=max(0LL,mx-b-1);
  ans+=max(0LL,mx-c-1);
  cout<<ans<<endl;
  return 0;
}