/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 19:07                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 10900 KB                             
*  problem: https://codeforces.com/contest/731/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=2e5;
int n,arr[N+2],dp[N+2];
int dfs(int st,int sum)
{
  if(st>n)return 0;
  if(dp[st]!=-1)return dp[st];
  int here=-inf,tmp=sum;
  for(int i=st;i<=n;i++)
  {
    tmp+=arr[i];
    here=max(here,tmp-dfs(i+1,tmp));
  }
  return dp[st]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(2,arr[1])<<endl;
   return 0;
}