/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 00:50                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/49/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   int a,b;
  cin>>a>>b;
   int c=a+b;
   int mx=0;
  while(a)
  {
    mx=max(mx,a%10);
    a/=10;
  }
  while(b)
  {
    mx=max(mx,b%10);
    b/=10;
  }
  mx++;
  int ans=0;
  while(c)
  {
    ans++;
    c/=mx;
  }
  cout<<ans<<endl;
   return 0;
}