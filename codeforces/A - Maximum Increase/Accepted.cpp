/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2019 18:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/702/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
   int now=1,ans=1;
  for(int i=2;i<=n;i++)
  {
    if(aa[i]>aa[i-1])now++;
    else now=1;
    ans=max(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}