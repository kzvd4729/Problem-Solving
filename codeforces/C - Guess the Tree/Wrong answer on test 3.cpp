/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2020 20:36                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 73500 KB                             
*  problem: https://codeforces.com/contest/429/problem/C
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],b[N+2],k,dp[30+2][30+2][(1<<14)+2];
void yo(){cout<<"YES"<<endl,exit(0);}
void no(){cout<<"NO"<<endl,exit(0);}
bool dfs(int id,int rm,int msk)
{
  if(id==k)
  {
    if(rm==0&&__builtin_popcount(msk)==k-1)return 1;
    return 0;
  }
  if(dp[id][rm][msk]!=-1)return dp[id][rm][msk];
  bool ret=0;
  for(int i=0;i<(1<<id);i++)
  {
    if(i&msk)continue;int sm=0;
    for(int j=0;j<id;j++)
    {
      if(i&(1<<j))sm+=b[j];
    }
    int tk=__builtin_popcount(i);
    if(sm<=b[id]&&tk+b[id]-sm>=2&&rm>=b[id]-sm)
    {
      ret|=dfs(id+1,rm-(b[id]-sm),msk|i);
    }
  }
  return dp[id][rm][msk]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;if(n==1)yo();
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)if(a[i]>1)b[k++]=a[i]-1;
  memset(dp,-1,sizeof dp);
  if(dfs(0,n-k,0))yo();else no();
   return 0;
}