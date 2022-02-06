/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2019 18:16                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++14                               
*  run_time: 5000 ms                                         memory_used: 4400 KB                              
*  problem: https://codeforces.com/contest/632/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
bitset<N+1>dp1,dp2;
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n,k;cin>>n>>k;k--;
 for(int i=1;i<=n;i++)
  cin>>aa[i],dp1[aa[i]]=1;
 while(k--)
 {
  dp2.reset();
  for(int i=1;i<=n;i++)
   dp2|=(dp1<<aa[i]);
  dp1=dp2;
 }
 for(int i=1;i<=N;i++)
  if(dp1[i])cout<<i<<" ";
 cout<<endl;
 return 0;
}