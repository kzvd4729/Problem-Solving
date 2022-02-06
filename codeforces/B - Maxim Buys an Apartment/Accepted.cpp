/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 16:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/854/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>x;
  if(x==0||x==n)cout<<0<<" ";
  else cout<<1<<" ";
   cout<<min(x*2,n-x)<<endl;
   return 0;
}