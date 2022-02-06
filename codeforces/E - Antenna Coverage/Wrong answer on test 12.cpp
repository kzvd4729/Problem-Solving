/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/18/2019 23:44                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 32100 KB                             
*  problem: https://codeforces.com/contest/1253/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int dp[80+2][N+2],n,m;
vector<pair<int,int> >v;
int dfs(int i,int j)
{
  if(j>m)return 0;
  if(i==n)return max(m-v.back().second,v.back().first-j);
   if(dp[i][j]!=-1)return dp[i][j];
   int nx=j;if(j>=v[i].first)nx=max(nx,v[i].second+1);
  int ret=dfs(i+1,nx);
  if(j<v[i].first)ret=min(ret,v[i].first-j+dfs(i+1,v[i].second+v[i].first-j+1));
  return dp[i][j]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x,s;cin>>x>>s;
    v.push_back({max(1,x-s),min(m,x+s)});
  }
  sort(v.begin(),v.end());
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,1)<<endl;
   return 0;
}