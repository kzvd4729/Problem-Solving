/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/26/2018 00:21                        
*  solution_verdict: Memory limit exceeded on test 6         language: GNU C++17                               
*  run_time: 1404 ms                                         memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/41/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int R=1e9;
const int N=1e2;
int n,m,k,mat[N+2][N+2];
int dp[N+2][N+2][10*N+2];
pair<int,int>path[N+2][N+2];
string s;
int dfs(int r,int c,int pea)
{
  if(r<1)
  {
    if(pea%k==0)return pea;
    else return 0;
  }
  if(c<1||c>m)return 0;
   if(dp[r][c][pea]!=-1)return dp[r][c][pea];
   int tmp1=dfs(r-1,c-1,pea+mat[r-1][c-1]);
  int tmp2=dfs(r-1,c+1,pea+mat[r-1][c+1]);
   if(tmp1>tmp2)path[r-1][c-1]={r,c};
  else path[r-1][c+1]={r,c};
   return dp[r][c][pea]=max(tmp1,tmp2);
 }
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>k;
  ++k;
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    for(int j=1;j<=m;j++)
      mat[i][j]=s[j-1]-'0';
  }
   memset(dp,-1,sizeof(dp));
  int mx=0,st;
  for(int i=1;i<=n;i++)
  {
    int tmp=dfs(n,i,mat[n][i]);
    if(tmp>mx)
    {
      mx=tmp;
      st=i;
    }
  }
  if(mx==0)cout<<-1<<endl,exit(0);
  int col=0,row=1;
  for(int j=1;j<=m;j++)
  {
    for(int k=0;k<=1000;k++)
    {
      if(dp[1][j][k]==mx)col=j;
    }
  }
  vector<char>vv;
  while(true)
  {
    int rr=path[row][col].first;
    int cc=path[row][col].second;
     if(cc<col)vv.push_back('R');
    else vv.push_back('L');
     row=rr;
    col=cc;
    if(row==n)break;
  }
  reverse(vv.begin(),vv.end());
  cout<<mx<<endl;
  cout<<col<<endl;
  for(auto x:vv)
    cout<<x;
  cout<<endl;
  return 0;
}