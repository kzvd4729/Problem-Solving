/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2018 23:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1084/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  long pra=0,prb=0;
  for(auto x:s)
  {
    if(x=='b')prb=pra;
    if(x=='a')pra=(pra+prb+1)%mod;
  }
  cout<<pra%mod<<endl;
  return 0;
}