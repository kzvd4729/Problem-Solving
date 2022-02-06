/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2019 20:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1165/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s,ans;cin>>s;char bf='#';
  for(auto x:s)
  {
    if(bf=='#')bf=x;
    else
    {
      if(bf==x)continue;
      ans.push_back(bf);
      ans.push_back(x);
      bf='#';
    }
  }
  cout<<s.size()-ans.size()<<endl;
  cout<<ans<<endl;
  return 0;
}