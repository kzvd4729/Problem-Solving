/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2019 16:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1220/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;int one=0,zero=0;
  for(auto x:s)
  {
    if(x=='n')one++;
    if(x=='z')zero++;
  }
  while(one--)
    cout<<1<<" ";
  while(zero--)
    cout<<0<<" ";
  cout<<endl;
  return 0;
}