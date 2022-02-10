/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-25 00:15:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 767                                        memory_used (MB): 10.1                            
*  problem: https://vjudge.net/problem/LightOJ-1299
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long mod=1000000007;
string s;long dp[N+2][N+2];
long dfs(int i,int ex)
{
  if(i==s.size())
  {
    if(ex==0)return 1;
    return 0;
  }
  if(dp[i][ex]!=-1)return dp[i][ex];
  long now;
  if(s[i]=='E')now=dfs(i+1,ex);
  else if(s[i]=='U')
  {
    now=ex*dfs(i+1,ex);
    now=(now+dfs(i+1,ex+1))%mod;
  }
  else
  {
    now=ex*dfs(i+1,ex-1);
    now=(now+dfs(i+1,ex))%mod;
    now=(now*ex)%mod;
  }
  return dp[i][ex]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    memset(dp,-1,sizeof(dp));
    cin>>s;cout<<"Case "<<++tc<<": "<<dfs(0,0)<<endl;
  }
  return 0;
}