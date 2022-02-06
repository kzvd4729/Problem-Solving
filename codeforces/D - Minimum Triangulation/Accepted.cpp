/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2019 21:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1140/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long ans=0;
  for(long i=2;i<n;i++)
    ans+=(i*(i+1));
  cout<<ans<<endl;
  return 0;
}