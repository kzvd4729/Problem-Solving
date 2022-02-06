/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/31/2018 14:23                        
*  solution_verdict: Time limit exceeded on test 8           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 294100 KB                            
*  problem: https://codeforces.com/contest/1013/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int N=5e3;
int n,arr[N+2],dp[N+2],vis[N+2][N+2][3];
void dfs(int st,int f,int cs,int cnt)
{
  dp[cnt]=min(dp[cnt],cs);
  if(st>n)return ;
   if(vis[st][cnt][f]<=cs)return ;
   int a,b;
  if(f)
  {
    dfs(st+1,0,cs,cnt);
    a=min(arr[st-1],arr[st-2]-1);
    a=max(0,a-arr[st]+1);
    b=max(0,arr[st+1]-arr[st]+1);
    dfs(st+2,1,cs+a+b,cnt+1);
  }
  else
  {
    dfs(st+1,0,cs,cnt);
    a=max(0,arr[st-1]-arr[st]+1);
    b=max(0,arr[st+1]-arr[st]+1);
    dfs(st+2,1,cs+a+b,cnt+1);
  }
  vis[st][cnt][f]=cs;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  arr[0]=-inf;
  arr[n+1]=-inf;
   for(int i=1;i<=n;i++)dp[i]=inf;
  for(int i=0;i<=N;i++)
  {
    for(int j=0;j<=N;j++)
    {
      for(int k=0;k<2;k++)
      {
        vis[i][j][k]=inf;
      }
    }
  }
   dfs(1,0,0,0);
   for(int i=1;i<=(n+1)/2;i++)
    cout<<dp[i]<<" ";
  cout<<endl;
  return 0;
}