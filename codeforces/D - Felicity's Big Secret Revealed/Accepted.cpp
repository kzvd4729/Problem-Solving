/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 00:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 888 ms                                          memory_used: 316300 KB                            
*  problem: https://codeforces.com/contest/757/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int n,dp[75+2][(1<<20)+2];string s;
bitset<10>b;int nx[75+2][10],ind[75+2][10];
int dfs(int i,int msk)
{
  if(i==n)
  {
    //b=msk;cout<<b<<endl;
    return (msk)&&(__builtin_popcount(msk+1)==1);
  }
  if(dp[i][msk]!=-1)return dp[i][msk];
  int nm=0,now=(msk)&&(__builtin_popcount(msk+1)==1);
  for(int j=1;nx[i][j]!=-1;j++)
  {
    now=(now+dfs(ind[i][j]+1,msk|(1<<(nx[i][j]-1))))%mod;
  }
  return dp[i][msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>s;memset(dp,-1,sizeof(dp));
  int sm=0;
  for(int i=0;i<n;i++)
  {
    int nm=0,id=0;
    for(int j=i;j<n;j++)
    {
      nm=nm*2+s[j]-'0';
      if(nm>20)break;
      if(nm)
      {
        nx[i][++id]=nm;
        ind[i][id]=j;
      }
    }
    nx[i][++id]=-1;
  }
  for(int i=0;i<n;i++)sm=(sm+dfs(i,0))%mod;
   cout<<sm<<endl;
    return 0;
}