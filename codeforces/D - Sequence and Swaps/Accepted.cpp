/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/30/2020 21:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 247600 KB                            
*  problem: https://codeforces.com/contest/1455/problem/D
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
const int N=500,inf=500+1,c=1;
int a[N+2],n;
short int dp[N+2][N+2][N+2];
int dfs(int i,int ls,int x)
{
  if(i>n)return 0;
  if(dp[i][ls][x]!=-1)return dp[i][ls][x];
  int ret=inf;
  if(a[i]>=ls)ret=min(ret,dfs(i+1,a[i],x));
  if(x>=ls&&a[i]>x)ret=min(ret,c+dfs(i+c,x,a[i]));
   return dp[i][ls][x]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int x;cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
     for(int i=0;i<=n+1;i++)
    {
      for(int ls=0;ls<=N+1;ls++)
        for(int x=0;x<=N+1;x++)dp[i][ls][x]=-1;
    }
    int ans=dfs(1,0,x);if(ans>N)ans=-1;
    cout<<ans<<'\n';
   }
  return 0;
}