/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2018 22:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1042/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,dp[N+2][3][3][3];
struct data
{
  int x;string s;
}arr[N+2];
int dfs(int st,int A,int B,int C)
{
  if(st>n)
  {
    if(A&&B&&C)return 0;
    else return 2e8;
  }
  if(dp[st][A][B][C]!=-1)return dp[st][A][B][C];
  int here=2e8;
  here=min(here,dfs(st+1,A,B,C));
  int a=A,b=B,c=C;
  for(auto x:arr[st].s)
  {
    if(x=='A')a=1;
    if(x=='B')b=1;
    if(x=='C')c=1;
  }
  here=min(here,arr[st].x+dfs(st+1,a,b,c));
  return dp[st][A][B][C]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i].x>>arr[i].s;
  memset(dp,-1,sizeof(dp));
  int ans=dfs(1,0,0,0);
  if(ans>1e8)ans=-1;
  cout<<ans<<endl;
  return 0;
}