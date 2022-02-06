/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/12/2018 12:37                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/990/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,a,b,ex;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 cin>>n>>m>>a>>b;
ex=n%m;
cout<<min(ex*b,(m-ex)*a)<<endl;
  return 0;
}