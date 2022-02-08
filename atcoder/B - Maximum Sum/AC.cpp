/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-05 18:05:13                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc096/tasks/abc096_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c,k;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>c>>k;
   if(b>a)swap(a,b);
  if(c>a)swap(c,a);
   while(k--)
    a=2*a;
   cout<<a+b+c<<endl;
   return 0;
}