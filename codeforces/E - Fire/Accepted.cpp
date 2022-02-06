/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 23:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3200 KB                              
*  problem: https://codeforces.com/contest/864/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int n,dp[N+N+2][4004];
struct data
{
  int t,d,v,id;
}arr[N+2];
bool cmp(data A,data B)
{
  return A.d<B.d;
}
int dfs(int st,int tim)
{
  if(st>n)return dp[st][tim]=0;
  if(dp[st][tim]!=-1)return dp[st][tim];
  int here=dfs(st+1,tim);
  if(tim+arr[st].t<arr[st].d)
    here=max(here,arr[st].v+dfs(st+1,tim+arr[st].t));
  return dp[st][tim]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i].t>>arr[i].d>>arr[i].v,arr[i].id=i;
  sort(arr+1,arr+n+1,cmp);
  memset(dp,-1,sizeof(dp));
  dfs(1,0);
//  for(int i=1;i<=n;i++)
//    cout<<arr[i].t<<" "<<arr[i].d<<" "<<arr[i].v<<" "<<arr[i].id<<endl;
//  for(int i=1;i<=n+1;i++)
//  {
//    for(int j=0;j<=15;j++)
//    {
//      cout<<dp[i][j]<<" ";
//    }
//    cout<<endl;
//  }
  //if(dp[1][0]==0)cout<<0<<endl<<0<<endl,exit(0);
  int tim=0;vector<int>ans;
  for(int i=1;i<=n;i++)
  {
    if(dp[i+1][tim+arr[i].t]==-1)continue;
    if(dp[i][tim]==dp[i+1][tim+arr[i].t]+arr[i].v)
    {
      ans.push_back(arr[i].id);
      tim+=arr[i].t;
    }
  }
  cout<<dp[1][0]<<endl;
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}