/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/21/2021 20:09                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 77 ms                                           memory_used: 43900 KB                             
*  problem: https://codeforces.com/contest/1516/problem/C
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
const int N=1e6,inf=1e9,mod=1e9+7;
 int n,a[N+2],dp[100+2][100000+2];
 bool dfs(int id,int vl)
{
  if(vl<0)return false;
  if(id>n)return (vl==0);
   if(dp[id][vl]!=-1)return dp[id][vl];
   return dp[id][vl]=(dfs(id+1,vl)|dfs(id+1,vl-a[id]));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;int sm=0;
  for(int i=1;i<=n;i++)cin>>a[i],sm+=a[i];
   if(sm%2)cout<<0<<endl,exit(0);
   memset(dp,-1,sizeof dp);
  if(dfs(1,sm/2)==0)cout<<0<<endl,exit(0);
   int mn=inf,pr;
   for(int i=1;i<=n;i++)
  {
    int x=(a[i]&(-a[i]));
    if(x<mn)mn=x,pr=i;
  }
  cout<<1<<" "<<pr<<endl;
  return 0;
}