/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/28/2018 16:23                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/607/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define lonf long long
using namespace std;
const int N=1e5;
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+n+1);
  int last=-1e9,ans=n;
  for(int i=1;i<=n;i++)
  {
    if(pp[i].first-pp[i].second>last)
      ans--,last=pp[i].first;
  }
  cout<<ans<<endl;
  return 0;
}