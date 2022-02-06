/****************************************************************************************
*  @author: kzvd4729                                         created: May/25/2020 10:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1144/problem/A
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
void solve()
{
  string s;cin>>s;
  int mn=1e9,mx=0;
  for(auto x:s)mn=min(mn,(int)x),mx=max(mx,(int)x);
  for(int i=0;i<s.size();i++)
  {
    for(int j=0;j<s.size();j++)
    {
      if(i!=j&&s[i]==s[j])mn=mx+1;
    }
  }
  if(mx-mn+1==s.size())cout<<"YES\n";
  else cout<<"NO\n";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}