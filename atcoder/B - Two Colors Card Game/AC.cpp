/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-17 18:51:43                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc091/tasks/abc091_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,ans;
string s;
map<string,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    mp[s]++;
  }
  cin>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>s;
    mp[s]--;
  }
  for(auto x:mp)ans=max(ans,x.second);
  cout<<ans<<endl;
  return 0;
}