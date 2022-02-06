/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/28/2019 19:49                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 8300 KB                              
*  problem: https://codeforces.com/contest/1107/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
long aa[N+2],n,dp[N+2][N+2][N+2];
vector<int>v;
long dfs(int i,int j,int ex)
{
  if(i==j)return aa[v[i]+ex];
  if(i>j)return 0;if(dp[i][j][ex]!=-1)return dp[i][j][ex];
  long now=0;
  for(int k=i;k<j;k++)
    now=max(now,dfs(i,k,ex)+dfs(k+1,j,0));
  now=max(now,aa[v[i]+ex]+dfs(i+1,j,0));
  now=max(now,aa[v[j]]+dfs(i,j-1,0));
  for(int k=i+2;k<=j;k+=2)
  {
    now=max(now,aa[ex+v[i]+v[k]]+dfs(i+1,k-1,0)+dfs(k+1,j,0));
    now=max(now,dfs(i+1,k-1,0)+aa[v[k+1]]+dfs(k+2,j,ex+v[i]+v[k]));
  }
  return dp[i][j][ex]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;string s;cin>>s;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)
    for(int j=0;j<=i;j++)
      aa[i]=max(aa[i],aa[j]+aa[i-j]);
  int cnt=0;char pr=s[0];s.push_back('2');
  for(int i=0;i<=n;i++)
  {
    if(s[i]==pr)cnt++;
    else
    {
      v.push_back(cnt);
      cnt=1;pr=s[i];
    }
  }
  n=v.size()-1;v.push_back(0);v.push_back(0);v.push_back(0);
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,n,0)<<endl;
  return 0;
}