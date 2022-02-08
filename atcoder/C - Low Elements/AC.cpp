/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-19 17:57:10                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 19 ms                                           memory_used: 1024 KB                              
*  problem: https://atcoder.jp/contests/abc152/tasks/abc152_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int mn=inf,cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(mn>=aa[i])cnt++;
    mn=min(mn,aa[i]);
  }
  cout<<cnt<<endl;
    return 0;
}