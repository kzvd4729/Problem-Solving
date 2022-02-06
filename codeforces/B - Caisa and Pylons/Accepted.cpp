/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2020 22:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/463/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int bl=0;long ans=0;
  for(int i=1;i<=n;i++)
  {
    bl+=aa[i-1]-aa[i];
    if(bl<0)ans-=bl,bl=0;
  }
  cout<<ans<<endl;
  return 0;
}