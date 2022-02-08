/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-10 18:09:19                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 48 ms                                           memory_used: 1536 KB                              
*  problem: https://atcoder.jp/contests/dp/tasks/dp_n
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e2;
int n,aa[N+2];long qm[N+2],dp[N+2][N+2];
long dfs(int lo,int hi)
{
  if(lo==hi)return 0;
  if(dp[lo][hi]!=-1)return dp[lo][hi];
  long now=1e18;
  for(int i=lo;i<hi;i++)
    now=min(now,dfs(lo,i)+dfs(i+1,hi));
  return dp[lo][hi]=now+qm[hi]-qm[lo-1];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
    qm[i]=aa[i]+qm[i-1];
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,n)<<endl;
   return 0;
}