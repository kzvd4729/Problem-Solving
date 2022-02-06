/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/31/2018 14:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 888 ms                                          memory_used: 294100 KB                            
*  problem: https://codeforces.com/contest/1013/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int N=5e3;
int n,arr[N+2],dp[N+2][N+2][3];
int ans[N+2];
int dfs(int st,int f,int cnt)
{
  if(st>n)
  {
    if(cnt==(n+1)/2)return 0;
    else return inf;
  }
  if(dp[st][cnt][f]!=-1)return dp[st][cnt][f];
  int a,b,here=inf;
  if(f)
  {
    here=min(here,dfs(st+1,0,cnt));
    a=min(arr[st-1],arr[st-2]-1);
    a=max(0,a-arr[st]+1);
    b=max(0,arr[st+1]-arr[st]+1);
    here=min(here,a+b+dfs(st+2,1,cnt+1));
  }
  else
  {
    here=min(here,dfs(st+1,0,cnt));
    a=max(0,arr[st-1]-arr[st]+1);
    b=max(0,arr[st+1]-arr[st]+1);
    here=min(here,a+b+dfs(st+2,1,cnt+1));
  }
  return dp[st][cnt][f]=here;
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
  memset(dp,-1,sizeof(dp));
   int x=(n+1)/2;
  for(int i=1;i<=x;i++)
    cout<<dfs(1,0,x-i)<<" ";
  cout<<endl;
  return 0;
}