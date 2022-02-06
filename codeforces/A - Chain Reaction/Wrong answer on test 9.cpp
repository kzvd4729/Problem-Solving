/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/28/2018 16:07                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/607/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define lonf long long
using namespace std;
const int N=1e5;
int dp[N+2],n;
pair<int,int>pp[N+2];
int _find(int i)
{
  int lo=1,hi=n,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(pp[md].first>=pp[i].first-pp[i].second)hi=md;
    else lo=md;
  }
  for(md=hi;md>=lo;md--)
  {
    if(pp[md].first<pp[i].first-pp[i].second)
      break;
  }
  return md;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>pp[i].first>>pp[i].second;
  //sort(pp+1,pp+n+1);
  dp[1]=1;
  for(int i=2;i<=n;i++)
  {
    dp[i]=max(dp[i-1],dp[_find(i)]+1);
  }
  cout<<n-dp[n]<<endl;
  return 0;
}