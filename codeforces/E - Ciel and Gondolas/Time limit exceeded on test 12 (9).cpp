/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2019 23:50                        
*  solution_verdict: Time limit exceeded on test 12          language: GNU C++14                               
*  run_time: 4000 ms                                         memory_used: 137900 KB                            
*  problem: https://codeforces.com/contest/321/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e3;
int mt[N+2][N+2],ds[N+2][N+2],dp[N+2][800+2],g;
void dfs(int lo,int hi,int lt,int rt)
{
  if(lo>hi)return ;
   if(lo==hi)
  {
    int &mn=dp[hi][g];
    for(int l=lt,r=min(hi,rt);l<=r;l++)
      mn=min(mn,ds[l][hi]+dp[l-1][g-1]);
    return ;
  }
  int md=(lo+hi)>>1;int &mn=dp[md][g],id;
  for(int l=lt,r=min(md,rt);l<=r;l++)
  {
    int now=ds[l][md]+dp[l-1][g-1];
    if(now<mn)mn=now,id=l;
  }
  dfs(lo,md-1,lt,id);dfs(md+1,hi,id,rt);
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
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=k;j++)
      dp[i][j]=1e9;
  }
  for(int j=1;j<=k;j++)
  {
    g=j;dfs(1,n,1,n);
  }
  printf("%d\n",dp[n][k]);
  return 0;
}