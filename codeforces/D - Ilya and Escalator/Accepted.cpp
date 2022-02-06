/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/06/2019 10:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 35400 KB                             
*  problem: https://codeforces.com/contest/518/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int n,t;bool vs[N+2][N+2];
double p,dp[N+2][N+2];
double dfs(int id,int tim)
{
  if(id>n||tim>t)return 0;
  if(vs[id][tim])return dp[id][tim];
  double ret=0;
  ret=p+p*dfs(id+1,tim+1);
  ret+=(1.0-p)*dfs(id,tim+1);
  vs[id][tim]=1;
  return dp[id][tim]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>p>>t;
  cout<<setprecision(6)<<fixed<<dfs(1,1)<<endl;
  return 0;
}