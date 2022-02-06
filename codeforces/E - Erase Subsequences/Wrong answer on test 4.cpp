/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2020 17:04                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 127100 KB                            
*  problem: https://codeforces.com/contest/1303/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string a,b;int n,m;
short int dp[400+2][400+2][400+2];
bool dfs(int i,int j,int k)
{
  if(i==m)return true;
  if(j==n&&k==n)return false;
   if(dp[i][j][k]!=-1)return dp[i][j][k];
  bool ret=false;
  if(j<n)
  {
    if(b[i]==a[j])ret|=dfs(i+1,j+1,k);
    else ret|=dfs(i,j+1,k);
  }
  if(k<n)
  {
    if(b[i]==a[k])ret|=dfs(i+1,j,k+1);
    else ret|=dfs(i,j,k+1); 
  }
  return dp[i][j][k]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>a>>b;n=a.size(),m=b.size();
    for(int i=0;i<=m;i++)
    {
      for(int j=0;j<=n;j++)
        for(int k=0;k<=n;k++)
          dp[i][j][k]=-1;
    }
    if(dfs(0,0,0))cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}