/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2021 17:03                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 2839 ms                                         memory_used: 38000 KB                             
*  problem: https://codeforces.com/contest/1527/problem/E
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=35000,inf=1e9,mod=1e9+7;
 int a[N+2];
int dp[100+2][N+2];
 deque<int>d[N+2];
  int L=1,R=0,C=0;
int ds(int lo,int hi)
{
  while(R<hi)
  {
    R++;int x=a[R];
     if((int)d[x].size()==0)
    {
      d[x].push_back(R);
    }
    else
    {
      int f=d[x].front(),s=d[x].back();
      C-=(s-f);
      d[x].push_back(R);
      C+=(R-f);
    }
   }
  while(L>lo)
  {
    L--;int x=a[L];
     if((int)d[x].size()==0)
    {
      d[x].push_front(L);
    }
    else
    {
      int f=d[x].front(),s=d[x].back();
      C-=(s-f);
      d[x].push_front(L);
      C+=(s-L);
    }
  }
  while(R>hi)
  {
    int x=a[R];
     int f=d[x].front(),s=d[x].back();
    C-=(s-f);
    d[x].pop_back();
    if((int)d[x].size())C+=(d[x].back()-f);
        R--;
  }
  while(L<lo)
  {
    int x=a[L];
     int f=d[x].front(),s=d[x].back();
    C-=(s-f);
    d[x].pop_front();
    if((int)d[x].size())C+=(s-d[x].front());
     L++;
  }
   return C;
}
 void dfs(int i,int lo,int hi,int lt,int rt)
{
  if(lo>hi)return ;
  int j=(lo+hi)>>1;int &mn=dp[i][j],op;
  for(int k=lt,r=min(j,rt);k<=r;k++)//condition have to be that way
  {
    int now=ds(k,j)+dp[i-1][k-1];
    if(now<mn)mn=now,op=k;//careful with op.
  }
  dfs(i,lo,j-1,lt,op);dfs(i,j+1,hi,op,rt);
}
   int main()              
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=0;i<=k;i++)for(int j=1;j<=n;j++)dp[i][j]=inf;
       for(int i=1;i<=k;i++)
  {
    dfs(i,1,n,1,n);
     //for(int j=1;j<=n;j++)cout<<dp[i][j]<<" ";cout<<endl;
  }
  cout<<dp[k][n]<<endl;
   //cout<<N*N<<endl;
      return 0;
}