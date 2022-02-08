/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-12-15 18:03:46                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 720 KB                               
*  problem: https://atcoder.jp/contests/agc029/tasks/agc029_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;long cnt=0,ans=0;
  for(auto x:s)
  {
    if(x=='B')cnt++;
    else ans+=cnt;
  }
  cout<<ans<<endl;
  return 0;
}