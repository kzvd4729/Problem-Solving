/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-09 18:18:45                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 512 KB                               
*  problem: https://atcoder.jp/contests/abc154/tasks/abc154_e
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
string s;long k;
long dp[1000+2][2][10+2];
long dfs(long p,long ck,long k)
{
  if(k<0)return 0;
  if(dp[p][ck][k]!=-1)return dp[p][ck][k];
  if(p==s.size())
  {
    if(k==0)return 1;return 0;
  }
  long nm=s[p]-'0',now=0;
  for(long i=0;i<10;i++)
  {
    if(!ck)
    {
      if(i==0)now+=dfs(p+1,0,k);else now+=dfs(p+1,0,k-1);
    }
    else
    {
      if(i>nm)continue;
      if(i==nm)
      {
        if(i==0)now+=dfs(p+1,1,k);else now+=dfs(p+1,1,k-1);
      }
      else
      {
        if(i==0)now+=dfs(p+1,0,k);else now+=dfs(p+1,0,k-1);
      }
    }
  }
  return dp[p][ck][k]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s>>k;
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,1,k)<<endl;
    return 0;
}