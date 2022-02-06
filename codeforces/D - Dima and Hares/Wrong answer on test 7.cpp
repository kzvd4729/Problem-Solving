/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/20/2019 20:20                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/358/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3;
int aa[N+2],bb[N+2],cc[N+2],dp[N+2][2],n;
int dfs(int i,int f)
{
 if(i>n)return 0;
 if(dp[i][f]!=-1)return dp[i][f];
 int now=0;
 if(f)
 {
  now=max(now,bb[i]+dfs(i+1,1));
  if(i<n)now=max(now,cc[i]+dfs(i+1,0));
 }
 else
 {
  now=max(now,aa[i]+dfs(i+1,1));
  if(i<n)now=max(now,bb[i]+dfs(i+1,0));
 }
 return dp[i][f]=now;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>n;
 for(int i=1;i<=n;i++)cin>>aa[i];
 for(int i=1;i<=n;i++)cin>>bb[i];
 for(int i=1;i<=n;i++)cin>>cc[i];
 memset(dp,-1,sizeof(dp));
 cout<<max(aa[1]+dfs(2,1),bb[1]+dfs(2,0))<<endl;
 return 0;
}