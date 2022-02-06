/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/07/2020 16:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1060 ms                                         memory_used: 240500 KB                            
*  problem: https://codeforces.com/contest/796/problem/E
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
const int N=1e3;
int n,k,a[N+2],b[N+2];
vector<vector<vector<vector<int> > > >dp;
int dfs(int i,int d1,int d2,int p)
{
  if(i>n)return 0;
  if(dp[i][p][d1][d2]!=-1)return dp[i][p][d1][d2];
  int ret=0;
  if(d1<k&&d2<k)ret=dfs(i+1,d1+1,d2+1,p)+(a[i]|b[i]);
  else if(d1==k&&d2==k)
  {
    ret=dfs(i+1,d1,d2,p);
    if(p)
    {
      ret=max(ret,dfs(i+1,1,d2,p-1)+a[i]);
      ret=max(ret,dfs(i+1,d1,1,p-1)+b[i]);
    }
  }
  else if(d1==k)
  {
    ret=dfs(i+1,d1,d2+1,p)+b[i];
    if(p)
    {
      ret=max(ret,dfs(i+1,1,d2+1,p-1)+(a[i]|b[i]));
    }
  }
  else if(d2==k)
  {
    ret=dfs(i+1,d1+1,d2,p)+a[i];
    if(p)
    {
      ret=max(ret,dfs(i+1,d1+1,1,p-1)+(a[i]|b[i]));
    }
  }
  return dp[i][p][d1][d2]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int p;cin>>n>>p>>k;
  int m;cin>>m;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;a[x]=1;
  }
  cin>>m;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;b[x]=1;
  }
  int mx=0;
  for(int i=1;i<=n;i++)mx+=(a[i]||b[i]);
  int tr=2*(n/k+1);if(tr<=p)cout<<mx<<endl,exit(0);
  dp.resize(n+2);
  for(int i=1;i<=n;i++)
  {
    dp[i].resize(p+2);
    for(int j=0;j<=p;j++)
    {
      dp[i][j].resize(k+2);
      for(int l=0;l<=k;l++)
        dp[i][j][l].assign(k+2,-1);
    }
  }
  ///for(int i=1;i<=n;i++)cout<<(a[i]|b[i])<<endl;
  cout<<dfs(1,k,k,p)<<endl;
      return 0;
}