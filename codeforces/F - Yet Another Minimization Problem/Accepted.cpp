/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 19:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 18000 KB                             
*  problem: https://codeforces.com/contest/868/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
 int fr[N+2],aa[N+2],lo,hi;
long dp[20+2][N+2];
long ret;
long cal(int lt,int rt)
{
  for(int i=lt;i<lo;i++)ret+=fr[aa[i]]++;
  for(int i=hi+1;i<=rt;i++)ret+=fr[aa[i]]++;
  for(int i=lo;i<lt;i++)ret-=--fr[aa[i]];
  for(int i=rt+1;i<=hi;i++)ret-=--fr[aa[i]];
  lo=lt,hi=rt;return ret;
}
void dfs(int i,int lo,int hi,int lt,int rt)
{
  //cout<<i<<" "<<lo<<" "<<hi<<" "<<lt<<" "<<rt<<endl;
  if(lo>hi)return ;
  int j=(lo+hi)>>1;long &mn=dp[i][j],op;
  for(int k=lt,r=min(j,rt);k<=r;k++)
  {
    long now=cal(k,j)+dp[i-1][k-1];
    if(now<mn)mn=now,op=k;
  }
  dfs(i,lo,j-1,lt,op);dfs(i,j+1,hi,op,rt);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;lo=1,hi=0;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=0;i<=k;i++)
    for(int j=1;j<=n;j++)dp[i][j]=1e15;
   for(int i=1;i<=k;i++)dfs(i,1,n,1,n);
  cout<<dp[k][n]<<endl;
   return 0;
}