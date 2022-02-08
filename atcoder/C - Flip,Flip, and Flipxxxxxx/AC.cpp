/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-11 18:19:23                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/arc091/tasks/arc091_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
   if(n==1&&m==1)
  {
    cout<<1<<endl;
    return 0;
  }
  if(n==2||m==2)
  {
    cout<<0<<endl;
    return 0;
  }
  if(n==1||m==1)
  {
    cout<<max(n,m)-2<<endl;
    return 0;
  }
  cout<<(n-2)*(m-2)<<endl;
   return 0;
}