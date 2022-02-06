/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2019 19:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/91/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],mn[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  mn[n+1]=2e9;
  for(int i=n;i>=1;i--)
    mn[i]=min(aa[i],mn[i+1]);
   for(int i=1;i<=n;i++)
  {
    int lo=i,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(mn[md]<aa[i])lo=md;
      else hi=md;
    }
    for(md=hi;md>=lo;md--)
      if(mn[md]<aa[i])break;
    int xx=md-i-1;
    if(xx==-2)xx++;
    cout<<xx<<" ";
  }
  cout<<endl;
  return 0;
}