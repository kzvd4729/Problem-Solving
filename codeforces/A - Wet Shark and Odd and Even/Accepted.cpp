/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 01:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/621/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,ans,mn=1e12,cnt;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    ans+=x;
    if(x&1)mn=min(mn,x),cnt++;
  }
  if(cnt&1)ans-=mn;
  cout<<ans<<endl;
  return 0;
}