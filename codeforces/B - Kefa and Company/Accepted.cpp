/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2018 15:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/580/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,d;cin>>n>>d;
  for(int i=1;i<=n;i++)
    cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+n+1);
  int lt=1;long cnt=0,mx=0;
  for(int i=1;i<=n;i++)
  {
    cnt+=pp[i].second*1LL;
    while(pp[i].first-pp[lt].first>=d)
      cnt-=pp[lt++].second*1LL;
    mx=max(mx,cnt);
  }
  cout<<mx<<endl;
  return 0;
}