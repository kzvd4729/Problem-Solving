/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/01/2018 22:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/276/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k,ans=-2e9;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int f,t;cin>>f>>t;
    if(t<=k)ans=max(ans,f);
    else ans=max(ans,f-(t-k));
  }
  cout<<ans<<endl;
  return 0;
}