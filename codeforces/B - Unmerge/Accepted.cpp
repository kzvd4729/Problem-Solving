/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/21/2020 21:38                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 77 ms                                           memory_used: 66400 KB                             
*  problem: https://codeforces.com/contest/1381/problem/B
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
//#define endl '\n'
#define long long long  
using namespace std;
const int N=4e3;
int n,a[N+2],nx[N+2],dp[N+2][N+2];
bool dfs(int i,int j)
{
  if(j<0)return 0;
  if(i>n+n)return j==0;
  if(dp[i][j]!=-1)return dp[i][j];
  bool ret=0;
  ret=dfs(nx[i],j);
  ret|=dfs(nx[i],j-(nx[i]-i));
  return dp[i][j]=ret;
}
void solve()
{
  cin>>n;
  for(int i=1;i<=n+n;i++)cin>>a[i];
  for(int i=1;i<=n+n;i++)
  {
    nx[i]=n+n+1;
    for(int j=i+1;j<=n+n;j++)
    {
      if(a[j]<a[i])continue;
      nx[i]=j;break;
    }
  }
  //for(int i=1;i<=n+n;i++)cout<<nx[i]<<" ";cout<<endl;
  for(int i=0;i<=n+n+1;i++)
  {
    for(int j=0;j<=n+n+1;j++)dp[i][j]=-1;
  }
  if(dfs(1,n))cout<<"YES\n";
  else cout<<"NO\n";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}