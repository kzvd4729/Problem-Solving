/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/27/2019 17:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1250/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int ans=1e9;
  for(int i=1;i<=n;i++)
    if(n%i==0)ans=min(ans,i*2+(n/i)*2);
  cout<<ans<<endl;
  return 0;
}