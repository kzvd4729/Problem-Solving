/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/14/2019 20:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 248 ms                                          memory_used: 134400 KB                            
*  problem: https://codeforces.com/contest/590/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=150;
int n,k,s,aa[N+2];
vector<vector<vector<int> > >dp;
int dfs(int i,int j,int m)
{
  if(m>s)return -1e9;
  if(i<1||j>n)return 0;
  if(dp[i][j-k][m]!=-1)return dp[i][j-k][m];
  int now=0;
  now=max(now,aa[i]-aa[j]+dfs(i-1,j+1,m+j-i));
  now=max(now,dfs(i,j+1,m));
  now=max(now,dfs(i-1,j,m));
  return dp[i][j-k][m]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k>>s;s=min(s,n*n);
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int sum=0;
  for(int i=1;i<=k;i++)
    sum+=aa[i];
   dp.resize(k+2);
  for(int i=0;i<k+2;i++)
  {
    dp[i].resize(n-k+2);
    for(int j=0;j<n-k+2;j++)
    {
      dp[i][j].resize((k+1)*(n-k+1),-1);
    }
  }
   cout<<sum-dfs(k,k+1,0)<<endl;
   return 0;
}