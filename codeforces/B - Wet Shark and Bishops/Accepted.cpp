/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 01:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/621/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,u,v,ans;
map<long,long>mp1,mp2;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>u>>v;
    mp1[u-v]++;
    mp2[u+v]++;
  }
  for(auto x:mp1)ans+=(x.second*(x.second-1))/2;
  for(auto x:mp2)ans+=(x.second*(x.second-1))/2;
  cout<<ans<<endl;
  return 0;
}