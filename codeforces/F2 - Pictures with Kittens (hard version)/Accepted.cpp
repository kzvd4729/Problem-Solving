/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/18/2018 16:37                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 592 ms                                          memory_used: 196100 KB                            
*  problem: https://codeforces.com/contest/1077/problem/F2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
const long inf=1e13;
int aa[N+2];
long dp[N+2][N+2];
deque<pair<long,long> >dq;
void insrt(int k,int j,int i)
{
  while(dq.size()&&dq.front().first<k)dq.pop_front();
  while(dq.size()&&dq.back().second<=dp[i][j])dq.pop_back();
  dq.push_back({i,dp[i][j]});
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,x;cin>>n>>k>>x;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=0;i<=N;i++)
    for(int j=0;j<=N;j++)
      dp[i][j]=-inf;
  dp[0][0]=0;
  for(int j=1;j<=x;j++)
  {
    dq.clear();
    for(int i=1;i<=n;i++)
    {
      insrt(i-k,j-1,i-1);
      long mx=dq.front().second;
      dp[i][j]=max(dp[i][j],mx+aa[i]);
    }
  }
  long mn=-inf;
  for(int i=n;i>=max(0,n-k+1);i--)
    mn=max(mn,dp[i][x]);
  if(mn<0)mn=-1;
  cout<<mn<<endl;
  return 0;
}