/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/27/2020 12:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 530 ms                                          memory_used: 86900 KB                             
*  problem: https://codeforces.com/contest/674/problem/C
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2];
double qm[N+2],rt[N+2],sm[N+2],dp[50+2][N+2];
double segment(int i,int j)
{
  double ret=qm[j]-qm[i-1];
  return ret-(sm[i-1]*(rt[j]-rt[i-1]));
}
void dfs(int i,int lo,int hi,int lt,int rt)
{
  if(lo>hi)return ;
  int j=(lo+hi)>>1;double &mn=dp[i][j],op;
  for(int k=lt,r=min(j,rt);k<=r;k++)
  {
    double now=segment(k,j)+dp[i-1][k-1];
    if(now<mn)mn=now,op=k;
  }
  dfs(i,lo,j-1,lt,op);dfs(i,j+1,hi,op,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<=n;i++)
  {
    sm[i]=sm[i-1]+aa[i];
    qm[i]=qm[i-1]+sm[i]/aa[i];
    rt[i]=rt[i-1]+1.0/aa[i];
  }
  cout<<setprecision(6)<<fixed;
  for(int i=0;i<=k;i++)for(int j=1;j<=n;j++)dp[i][j]=1e18;
  for(int i=1;i<=k;i++)dfs(i,1,n,1,n);
  cout<<dp[k][n]<<endl;
   return 0;
}