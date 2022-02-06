/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/29/2020 20:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/1389/problem/B
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
const int N=1e5;
int n,k,z,a[N+2],dp[N+2][2][5+2];
int dfs(int i,int k,int l,int z)
{
  if(k==0)return 0;
  if(dp[i][l][z]!=-1)return dp[i][l][z];
  int ret=0;
  if(i<n)ret=a[i+1]+dfs(i+1,k-1,0,z);
  if(l==0&&i>1&&z)ret=max(ret,a[i-1]+dfs(i-1,k-1,1,z-1));
  return dp[i][l][z]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>k>>z;
    for(int i=1;i<=n;i++)cin>>a[i];
     for(int i=0;i<=n+1;i++)
    {
      for(int l=0;l<2;l++)
        for(int z=0;z<7;z++)dp[i][l][z]=-1;
    }
    cout<<a[1]+dfs(1,k,0,z)<<'\n';
  }
  return 0;
}