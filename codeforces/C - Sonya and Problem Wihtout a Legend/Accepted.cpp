/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/31/2019 19:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1029 ms                                         memory_used: 119000 KB                            
*  problem: https://codeforces.com/contest/713/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3,inf=1e9;
int aa[N+2];long dp[N+2][N+2];
vector<int>v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)v[i].push_back(aa[j]+i-j);
    sort(v[i].begin(),v[i].end());
  }
  for(int i=0;i<=N;i++)
  {
    for(int j=0;j<=N;j++)dp[i][j]=1e17;
  }
  v[0].push_back(-1e9);dp[0][0]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<v[i].size();j++)
    {
      if(j)dp[i][j]=dp[i][j-1];
      int id=lower_bound(v[i-1].begin(),v[i-1].end(),v[i][j])-v[i-1].begin();
      id--;
      dp[i][j]=min(dp[i][j],dp[i-1][id]+abs(aa[i]-v[i][j]));
    }
  }
  cout<<dp[n][v[n].size()-1]<<endl;
  return 0;
}