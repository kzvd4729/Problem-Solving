/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2020 18:38                        
*  solution_verdict: Time limit exceeded on test 26          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/1348/problem/E
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
#define long long long
using namespace std;
const int N=5e2,mod=1e9+7;
int n,aa[N+2],bb[N+2],k;
long dp[N+2][N+2];
long dfs(int i,int a,int b)
{
  long in=a/k+b/k;a%=k,b%=k;
  if(i>n)return in;
  //if(dp[i][a]!=-1)return dp[i][a];
  long ret=aa[i]/k+bb[i]/k+dfs(i+1,a+aa[i]%k,b+bb[i]%k);
  int r=min(k-1,aa[i]);
  for(int c=1;c<=r;c++)
  {
    if(k-c>bb[i])continue;
    int ta=aa[i]-c,tb=bb[i]-(k-c);
    ret=max(ret,1+ta/k+tb/k+dfs(i+1,a+ta%k,b+tb%k));
  }
  return dp[i][a]=ret+in;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i];
  memset(dp,-1,sizeof dp);
  cout<<dfs(1,0,0)<<endl;
  return 0;
}