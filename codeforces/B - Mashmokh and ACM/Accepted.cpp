/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/22/2020 17:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 16100 KB                             
*  problem: https://codeforces.com/contest/414/problem/B
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
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=2e3,mod=1000000007;
vector<int>d[N+2];
void dd()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)d[j].push_back(i);
  }
}
int n,k,dp[N+2][N+2];
int dfs(int l,int k)
{
  if(k==0)return 1;
  if(dp[l][k]!=-1)return dp[l][k];
  int now=0;
  for(auto x:d[l])
    now=(now+dfs(x,k-1))%mod;
  return dp[l][k]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  dd();cin>>n>>k;memset(dp,-1,sizeof dp);
   int now=0;
  for(int i=1;i<=n;i++)
    now=(now+dfs(i,k-1))%mod;
   cout<<now<<endl;
   return 0;
}