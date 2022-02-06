/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2019 15:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1151/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>pp[N+2];
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
  return p1.second+p2.first<p1.first+p2.second;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+n+1,cmp);
  long ans=0;
  for(int i=1;i<=n;i++)
    ans+=((pp[i].first*1LL)*(i-1))+((pp[i].second*1LL)*(n-i));
  cout<<ans<<endl;
  return 0;
}