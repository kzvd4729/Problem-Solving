/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-01 18:06:22                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
   for(int i=1;i<=n;i++)
  {
    if(n==(i*108)/100)cout<<i<<endl,exit(0);
  }
  cout<<":("<<endl;
    return 0;
}