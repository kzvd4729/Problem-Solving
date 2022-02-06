/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2021 02:07                        
*  solution_verdict: Time limit exceeded on test 44          language: GNU C++17 (64)                          
*  run_time: 2000 ms                                         memory_used: 99000 KB                             
*  problem: https://codeforces.com/contest/1499/problem/F
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
const int N=5000,inf=1e9,mod=998244353;
  vector<int>ad[N+2];int k;
int dp[N+2][N+2],tmp[N+2];
void dfs(int nd,int pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd);
  }
   int f=0;dp[nd][0]=1;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
     int ex=dp[x][k];
    for(int i=k;i>=1;i--)dp[x][i]=dp[x][i-1];
    dp[x][0]=ex;
    for(int i=1;i<=k;i++)dp[x][0]=(dp[x][0]+dp[x][i])%mod;
     //if(nd==1)cout<<nd<<"**"<<dp[x][0]<<endl;
     if(f==0)
    {
      for(int i=0;i<=k;i++)dp[nd][i]=dp[x][i];
      f=1;continue;
    }
      for(int i=0;i<=k;i++)tmp[i]=dp[nd][i];
    for(int i=0;i<=k;i++)dp[nd][i]=0;
     for(int i=0;i<=k;i++)
    {
      for(int j=0;j<i;j++)//any previous subtree is strictly maximum
      {
        if(i+j<=k)
        {
          dp[nd][i]=(dp[nd][i]+1LL*tmp[i]*dp[x][j])%mod;
        }
      }
      for(int j=i;j<=k;j++)//this subtree is maximum
      {
        if(i+j<=k)
        {
          dp[nd][j]=(dp[nd][j]+1LL*tmp[i]*dp[x][j])%mod;
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);ad[v].push_back(u);
  }
  dfs(1,0);int ans=0;
  for(int i=0;i<=k;i++)ans=(ans+dp[1][i])%mod;
  cout<<ans<<endl;
   //for(int i=0;i<=k;i++)cout<<"["<<i<<"]"<<" "<<dp[1][i]<<endl;
   return 0;
}