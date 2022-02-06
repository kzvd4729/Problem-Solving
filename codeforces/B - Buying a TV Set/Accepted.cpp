/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2018 16:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1041/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long a,b,x,y;cin>>a>>b>>x>>y;
  long gcd=__gcd(x,y);
  x/=gcd;y/=gcd;
  cout<<min(a/x,b/y)<<endl;
   return 0;
}