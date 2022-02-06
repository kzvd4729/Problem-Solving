/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2021 16:51                        
*  solution_verdict: Time limit exceeded on test 39          language: GNU C++17 (64)                          
*  run_time: 3000 ms                                         memory_used: 44300 KB                             
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
inline void add(int x,int i)
{
  if((int)d[x].size())C-=(d[x].back()-d[x].front());
  if(i<d[x].front())d[x].push_front(i);
  else d[x].push_back(i);
   C+=d[x].back()-d[x].front();
}
inline void rem(int x,int i)
{
  C-=(d[x].back()-d[x].front());
   if(i==d[x].front())d[x].pop_front();
  else if(i==d[x].back())d[x].pop_back();
  else assert(0);
   if((int)d[x].size())C+=(d[x].back()-d[x].front());
}
int ds(int lo,int hi)
{
  while(R<hi){R++;add(a[R],R);}
  while(L>lo){L--;add(a[L],L);}
  while(R>hi){rem(a[R],R);R--;}
  while(L<lo){rem(a[L],L);L++;}
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