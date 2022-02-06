/****************************************************************************************
*  @author: kzvd4729                                         created: May/27/2018 21:09                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 420 ms                                          memory_used: 7900 KB                              
*  problem: https://codeforces.com/contest/981/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ans,a,b,n;
map<long,long>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a>>b;
    mp[a]=max(mp[a],b);
  }
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a>>b;
    mp[a]=max(mp[a],b);
  }
  for(auto x:mp)
    ans+=x.second;
  cout<<ans<<endl;
  return 0;
}