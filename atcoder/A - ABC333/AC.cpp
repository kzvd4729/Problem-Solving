/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-08 18:02:08                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc109/tasks/abc109_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int a,b;cin>>a>>b;
  if(a>b)swap(a,b);
  for(int i=a;i<=b;i++)
    if((a*b*i)%2)cout<<"Yes"<<endl,exit(0);
  cout<<"No"<<endl;
   return 0;
}