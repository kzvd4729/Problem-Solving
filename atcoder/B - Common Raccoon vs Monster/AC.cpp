/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-26 18:02:52                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 9 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc153/tasks/abc153_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;cin>>a>>b;
  int sm=0;
  for(int i=1;i<=b;i++)
  {
    int x;cin>>x;sm+=x;
  }
  if(sm>=a)cout<<"Yes\n";
  else cout<<"No\n";
    return 0;
}