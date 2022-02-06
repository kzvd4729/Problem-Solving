/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/28/2018 16:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 1200 KB                              
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
  int lo=1,hi=i,md;
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
  sort(pp+1,pp+n+1);
  dp[1]=1;int mx=1;
  for(int i=2;i<=n;i++)
  {
    int id=_find(i);
    dp[i]=dp[id]+1;mx=max(mx,dp[i]);
  }
  cout<<n-mx<<endl;
  return 0;
}