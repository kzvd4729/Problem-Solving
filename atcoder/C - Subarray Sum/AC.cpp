/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-18 18:19:48                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 10 ms                                           memory_used: 1280 KB                              
*  problem: https://atcoder.jp/contests/keyence2020/tasks/keyence2020_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k,s;cin>>n>>k>>s;
   for(int i=1;i<=k;i++)
    cout<<s<<" ";
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  for(int i=k+1;i<=n;i++)
    cout<<1+rng()%inf<<" ";
  cout<<endl;
    return 0;
}