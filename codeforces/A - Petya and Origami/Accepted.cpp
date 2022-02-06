/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/24/2018 13:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1080/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;cin>>n>>k;
   long rd=2*n,gr=5*n,bl=8*n;
   long ans=(rd+k-1)/k+(gr+k-1)/k+(bl+k-1)/k;
  cout<<ans<<endl;
   return 0;
}