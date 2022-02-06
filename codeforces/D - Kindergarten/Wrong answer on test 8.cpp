/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2018 01:53                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/484/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,arr[N+2];
long dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  dp[2]=abs(arr[2]-arr[1])*1LL;
  for(int i=3;i<=n;i++)
  {
    int f1=0,f2=0;
    if(arr[i]>=arr[i-1])f1=1;
    if(arr[i-1]>=arr[i-2])f2=1;
    if(f1==f2)dp[i]=dp[i-1]+abs(arr[i]-arr[i-1])*1LL;
    else dp[i]=dp[i-2]+abs(arr[i]-arr[i-1])*1LL;
  }
  cout<<dp[n]<<endl;
  return 0;
}