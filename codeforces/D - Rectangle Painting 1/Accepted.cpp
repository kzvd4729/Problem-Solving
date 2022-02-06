/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2020 18:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 421 ms                                          memory_used: 32400 KB                             
*  problem: https://codeforces.com/contest/1198/problem/D
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
const int N=50,inf=1e9+2;
int n,dp[N+2][N+2][N+2][N+2];
string s[N+2];
int dfs(int a,int b,int c,int d)
{
  if(a==b&&c==d)return s[a][c]=='#';
  if(dp[a][b][c][d]!=-1)return dp[a][b][c][d];
  int ans=inf;
  if(b-a>d-c)
  {
    ans=b-a+1;
    for(int i=a;i<b;i++)
      ans=min(ans,dfs(a,i,c,d)+dfs(i+1,b,c,d));
  }
  else
  {
    ans=d-c+1;
    for(int i=c;i<d;i++)
      ans=min(ans,dfs(a,b,c,i)+dfs(a,b,i+1,d)); 
  }
  return dp[a][b][c][d]=ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>s[i],s[i]="#"+s[i];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,n,1,n)<<endl;
  return 0;
}