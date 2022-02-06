/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2020 17:44                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 3960 ms                                         memory_used: 129200 KB                            
*  problem: https://codeforces.com/contest/321/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e3;
int mt[N+2][N+2],ds[N+2][N+2],dp[N+2],pr[N+2],g;
void dfs(int i,int lo,int hi,int lt,int rt)
{
  if(lo>hi)return ;
  int j=(lo+hi)>>1;int &mn=dp[j],op;
  for(int k=lt,r=min(j,rt);k<=r;k++)
  {
    int now=ds[k][j]+pr[k-1];
    if(now<mn)mn=now,op=k;
  }
  dfs(i,lo,j-1,lt,op);dfs(i,j+1,hi,op,rt);
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;//cin>>n>>k;
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      //cin>>mt[i][j];
      scanf("%d",&mt[i][j]);
      mt[i][j]+=mt[i][j-1];
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
      ds[i][j]=ds[i][j-1]+mt[j][j]-mt[j][i-1];
  }
  for(int j=0;j<=n;j++)dp[j]=1e9;dp[0]=0;
  for(int i=1;i<=k;i++)
  {
    for(int j=0;j<=n;j++){pr[j]=dp[j];dp[j]=1e9;}
    dp[0]=0;
    dfs(i,1,n,1,n);
  }
  printf("%d\n",dp[n]);
  return 0;
}