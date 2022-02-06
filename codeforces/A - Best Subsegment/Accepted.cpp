/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/18/2019 21:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1117/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int mx=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];mx=max(mx,aa[i]);
  }
  int ans=0,cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]==mx)cnt++;
    else cnt=0;
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}