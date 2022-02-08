/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-14 18:03:27                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long a,b;cin>>a>>b;
  cout<<(a*b+1)/2<<endl;
    return 0;
}