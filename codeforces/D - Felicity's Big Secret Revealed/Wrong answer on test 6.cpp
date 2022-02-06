/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 00:03                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 316000 KB                            
*  problem: https://codeforces.com/contest/757/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int n,dp[75+2][(1<<20)+2];string s;
bitset<10>b;
int dfs(int i,int msk)
{
  if(i==n)
  {
    //b=msk;cout<<b<<endl;
    return (msk)&&(__builtin_popcount(msk+1)==1);
  }
  int nm=0,now=(msk)&&(__builtin_popcount(msk+1)==1);
  for(int j=i;j<i+5;j++)
  {
    if(j>=n)break;nm=nm*2+s[j]-'0';
    if(nm>20)break;
    if(nm)now=(now+dfs(j+1,msk|(1<<(nm-1))))%mod;
  }
  return dp[i][msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>s;memset(dp,-1,sizeof(dp));
  int sm=0;
  for(int i=0;i<n;i++)sm=(sm+dfs(i,0))%mod;
   cout<<sm<<endl;
    return 0;
}