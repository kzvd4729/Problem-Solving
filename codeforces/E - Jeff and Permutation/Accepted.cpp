/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/15/2018 23:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/351/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int n,lft[N+2],rgt[N+2];
int dp[N+2][N+2];
pair<int,int>arr[N+2];
int dfs(int st,int neg)
{
  if(st<1)return 0;
  if(dp[st][neg]!=-1)return dp[st][neg];
  if(arr[st].first!=arr[st+1].first)neg=0;
  int here=1e9;
  here=min(here,rgt[arr[st].second]+neg+dfs(st-1,neg));
  here=min(here,lft[arr[st].second]+dfs(st-1,neg+1));
  return dp[st][neg]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i].first;
    arr[i].first=abs(arr[i].first);
    arr[i].second=i;
  }
  for(int i=1;i<=n;i++)
  {
    int on=0,tw=0;
    for(int j=1;j<=n;j++)
    {
      if(arr[j].first<arr[i].first)
      {
        if(j<i)on++;
        else tw++;
      }
    }
    lft[i]=on,rgt[i]=tw;
  }
//  for(int i=1;i<=n;i++)
//    cout<<lft[i]<<" "<<rgt[i]<<endl;
  sort(arr+1,arr+n+1);
  memset(dp,-1,sizeof(dp));
  cout<<dfs(n,0)<<endl;
  return 0;
}