/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-17 14:51:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-900
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long fib[52],n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fib[1]=1LL;
  fib[2]=2LL;
  for(int i=3;i<=50;i++)
    fib[i]=fib[i-1]+fib[i-2];
  while(cin>>n)
  {
    if(!n)break;
    cout<<fib[n]<<endl;
  }
  return 0;
}