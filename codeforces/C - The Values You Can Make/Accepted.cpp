/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2020 18:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 826 ms                                          memory_used: 247600 KB                            
*  problem: https://codeforces.com/contest/687/problem/C
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#define long long long
using namespace std;
const int N=5e2,R=1e9;
int n,k,aa[N+2];
bool dp[N+2][N+2][N+2],vs[N+2][N+2][N+2];
bool dfs(int i,int j,int k)
{
  if(i>n)return (j==0&&k==0);
  if(vs[i][j][k])return dp[i][j][k];
  vs[i][j][k]=1;bool now=dfs(i+1,j,k);
  if(aa[i]<=j)now|=dfs(i+1,j-aa[i],k);
  if(aa[i]<=k)now|=dfs(i+1,j,k-aa[i]);
  return dp[i][j][k]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  vector<int>ans;
  for(int i=0;i<=k;i++)
    if(dfs(1,i,k-i))ans.push_back(i);
  cout<<ans.size()<<"\n";
  for(auto x:ans)cout<<x<<" ";
  cout<<endl;
  return 0;
}