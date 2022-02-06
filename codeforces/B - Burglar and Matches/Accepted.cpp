/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2018 19:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/16/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
    cin>>pp[i].second>>pp[i].first;
  sort(pp+1,pp+m+1,greater<pair<int,int> >());
   long ans=0;
  for(int i=1;i<=m;i++)
  {
    pp[i].second=min(pp[i].second,n);
    ans+=((pp[i].first*1LL)*pp[i].second);
    n-=pp[i].second;
  }
  cout<<ans<<endl;
  return 0;
}