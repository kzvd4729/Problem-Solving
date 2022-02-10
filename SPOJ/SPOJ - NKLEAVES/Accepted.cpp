/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-07-07 16:40:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 190                                        memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-NKLEAVES
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
int a[N+2];long qm[N+2],an[N+2],dp[10+2][N+2];
void dfs(int i,int lo,int hi,int lt,int rt)
{
  if(lo>hi)return ;
  int j=(lo+hi)>>1,op;long &mn=dp[i][j],now;
  for(int k=lt,r=min(j,rt);k<=r;k++)
  {
    now=an[j]-an[k-1]-(qm[j]-qm[k-1])*(k-1)+dp[i-1][k-1];
    //cout<<k<<" "<<j<<" "<<an[j]-an[k-1]-(qm[j]-qm[k-1])*(k-1)<<endl;
    if(now<mn)mn=now,op=k;
  }
  dfs(i,lo,j-1,lt,op);dfs(i,j+1,hi,op,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i],qm[i]=qm[i-1]+a[i];
  for(int i=1;i<=n;i++)an[i]=an[i-1]+1LL*a[i]*(i-1);

  memset(dp,60,sizeof dp);
  for(int i=0;i<10+2;i++)dp[i][0]=0;

  for(int i=1;i<=k;i++)dfs(i,1,n,1,n);
  cout<<dp[k][n]<<endl;
  
  return 0;
}