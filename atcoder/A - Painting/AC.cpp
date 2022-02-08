/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-18 18:01:42                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/keyence2020/tasks/keyence2020_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int h,w,n;cin>>h>>w>>n;
   if(h<w)swap(h,w);
   cout<<(n+h-1)/h<<endl;
    return 0;
}