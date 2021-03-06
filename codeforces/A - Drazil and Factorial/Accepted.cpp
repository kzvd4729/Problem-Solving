/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/03/2019 10:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/516/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e5;
int fac[10],dp[N+2];
vector<int>v,wy[10];
int dfs(int nm)
{
  if(nm==1)return dp[nm]=0;
  if(dp[nm]!=-1)return dp[nm];
  int now=-1e9;
  for(int i=2;i<=9;i++)
  {
    if(nm%fac[i]==0)
      now=max(now,1+dfs(nm/fac[i]));
  }
  return dp[nm]=now;
}
void path(int nm)
{
  while(nm>1)
  {
    for(int i=2;i<=9;i++)
    {
      if(nm%fac[i]==0&&dp[nm]==dp[nm/fac[i]]+1)
      {
        v.push_back(i);nm/=fac[i];
        break;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1;for(int i=1;i<=9;i++)fac[i]=fac[i-1]*i;
  for(int i=2;i<=9;i++)
  {
    memset(dp,-1,sizeof(dp));
    dfs(fac[i]);v.clear();path(fac[i]);
    wy[i]=v;
  }
  int n;cin>>n;string s;cin>>s;
  vector<int>ans;
  for(auto x:s)
  {
    int xx=x-'0';
    if(xx<=1)continue;
    for(auto z:wy[xx])
      ans.push_back(z);
  }
  sort(ans.begin(),ans.end(),greater<int>());
  for(auto x:ans)
    cout<<x;
  cout<<endl;
  return 0;
}