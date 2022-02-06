/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/19/2021 22:22                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1474/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9,mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;long ans=0;
    for(int i=1;i<n;i++)
      ans+=(1LL*i*i);
    cout<<ans<<'\n';
    for(int i=2;i<=n;i++)cout<<i<<" ";cout<<1<<'\n';
     cout<<n-1<<'\n';
    for(int i=1;i<n;i++)cout<<i<<" "<<n<<'\n';
  }
  return 0;
}