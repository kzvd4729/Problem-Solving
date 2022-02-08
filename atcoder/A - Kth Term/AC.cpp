/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-14 18:01:25                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x;cin>>x;
  cout<<aa[x-1]<<endl;
    return 0;
}