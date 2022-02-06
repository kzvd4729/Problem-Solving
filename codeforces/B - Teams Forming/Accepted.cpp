/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/18/2018 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1092/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1);
  int ans=0;
  for(int i=1;i<=n;i+=2)
    ans+=aa[i+1]-aa[i];
  cout<<ans<<endl;
   return 0;
}