/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2020 17:40                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4600 KB                              
*  problem: https://codeforces.com/contest/1303/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string a,b;int n,m;
int dp[400+2][400+2],vis[N+2];
bool dfs(int i,int j)
{
  if(i==m)return true;
  if(j==n)return false;
   if(dp[i][j]!=-1)return dp[i][j];
  bool ret=false;
  ret=dfs(i,j+1);
  if(!vis[j]&&b[i]==a[j])ret|=dfs(i+1,j+1);
   return dp[i][j]=ret;
}
bool solve(int i)
{
  for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)dp[i][j]=-1;
  }
  return dfs(i+1,0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>a>>b;n=a.size(),m=b.size();
     int pt=0,f=0;
    for(int i=0;i<m;i++)
    {
      while(pt<n)
      {
        if(b[i]==a[pt])
        {
          vis[pt]=1;if(solve(i))f=1;
          pt++;break;
        }
        pt++;
      }
      if(f)break;
    }
    reverse(a.begin(),a.end());reverse(b.begin(),b.end());
    memset(vis,0,sizeof(vis));
    pt=0;
    for(int i=0;i<m;i++)
    {
      while(pt<n)
      {
        if(b[i]==a[pt])
        {
          vis[pt]=1;if(solve(i))f=1;
          pt++;break;
        }
        pt++;
      }
      if(f)break;
    }
    if(f)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}