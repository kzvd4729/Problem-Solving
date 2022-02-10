/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-07-07 17:31:21                      
*  solution_verdict: Terminated due to timeout               language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-mining
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
const int N=5e3;
int p[N+2],w[N+2];long lft[N+2][N+2],rgt[N+2][N+2];
long cal(int i,int md,int j)
{
  return lft[i][md]+rgt[md][j];
}
void dfs(int i,int lo,int hi,int lt,int rt)
{
  if(lo>hi)return ;
  int j=(lo+hi)>>1,op;long &mn=lft[i][j],now;
  for(int k=lt,r=min(j,rt);k<=r;k++)
  {
    now=rgt[k][j]+lft[i-1][k-1];
    if(now<mn)mn=now,op=k;
  }
  dfs(i,lo,j-1,lt,op);dfs(i,j+1,hi,op,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>p[i]>>w[i];

  for(int l=1;l<=n;l++)
  {
    for(int i=1;i+l<=n;i++)
    {
      int j=i+l;
      lft[i][j]=lft[i+1][j]+(p[j]-p[i])*1LL*w[i];
      rgt[i][j]=rgt[i][j-1]+(p[j]-p[i])*1LL*w[j];
    }
  }
  for(int i=1;i<=n;i++)
  {
    int pt=i;
    for(int j=i+1;j<=n;j++)
    {
      while(pt<j&&cal(i,pt+1,j)<cal(i,pt,j))pt++;
      rgt[i][j]=cal(i,pt,j);
    }
  }
  memset(lft,60,sizeof lft);
  for(int i=0;i<N+2;i++)lft[i][0]=0;

  for(int i=1;i<=k;i++)dfs(i,1,n,1,n);
  cout<<lft[k][n]<<endl;

  return 0;
}