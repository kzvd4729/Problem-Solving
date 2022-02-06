/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/30/2021 23:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 45000 KB                             
*  problem: https://codeforces.com/contest/1498/problem/F
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
const int N=1e5,inf=1e9,mod=1e9+7;
 int a[N+2],k;
vector<int>ad[N+2];
 int dp[N+2][40+2];
void dfs(int nd,int pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd);
     for(int i=0;i<k;i++)dp[nd][i]^=dp[x][i];
  }
  int tmp=dp[nd][k-1];
  for(int i=k-2;i>=0;i--)dp[nd][i+1]=dp[nd][i];
  dp[nd][0]=tmp^a[nd];
}
 int ans[N+2];
void dds(int nd,int pr)
{
  int xr=0;
  for(int i=k/2;i<k;i++)xr^=dp[nd][i];
  ans[nd]=(bool)xr;
   for(auto x:ad[nd])
  {
    if(x==pr)continue;
     int tmp[40+2];
    for(int i=0;i<k;i++)tmp[i]=dp[nd][i];
     for(int i=1;i<k;i++)dp[nd][i]^=dp[x][i-1];
    dp[nd][0]^=dp[x][k-1];
     int tmp2=dp[nd][k-1];
    for(int i=k-2;i>=0;i--)dp[nd][i+1]=dp[nd][i];
    dp[nd][0]=tmp2;
      for(int i=0;i<k;i++)dp[x][i]^=dp[nd][i];
    dds(x,nd);
    for(int i=0;i<k;i++)dp[x][i]^=dp[nd][i];
      for(int i=0;i<k;i++)dp[nd][i]=tmp[i];
   }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n>>k;k+=k;
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);ad[v].push_back(u);
  }
   for(int i=1;i<=n;i++)cin>>a[i];
  dfs(1,-1);
  //cout<<"Here"<<endl;
  dds(1,-1);
   for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
   return 0;
}