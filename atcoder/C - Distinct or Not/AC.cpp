/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-09 18:04:02                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 121 ms                                          memory_used: 9600 KB                              
*  problem: https://atcoder.jp/contests/abc154/tasks/abc154_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;set<int>st;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;st.insert(x);
  }
  if(st.size()==n)cout<<"YES\n";
  else cout<<"NO\n";
    return 0;
}