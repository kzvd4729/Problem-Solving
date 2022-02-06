/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/07/2019 22:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 110100 KB                            
*  problem: https://codeforces.com/contest/1133/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],fr[N+2],n,k,nxt[N+2];
int dp[5005][5005];
vector<int>v;
int dfs(int i,int j)
{
  if(j>k)return -1e8;
  if(i>=v.size())return 0;
  if(dp[i][j]!=-1)return dp[i][j];
  int now=-1e8;
  now=max(now,dfs(i+1,j));
  now=max(now,nxt[i]-i+dfs(nxt[i],j+1));
  return dp[i][j]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;v.push_back(x);
  }
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++)
  {
    int id=upper_bound(v.begin(),v.end(),v[i]+5)-v.begin();
    nxt[i]=id;
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0)<<endl;
  return 0;
}