/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 23:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/474/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;long sum=0;vector<long>v;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;sum+=x*1LL;
    v.push_back(sum);
  }
  int m;cin>>m;
  while(m--)
  {
    long x;cin>>x;
    int id=lower_bound(v.begin(),v.end(),x)-v.begin();
    cout<<id+1<<"\n";
  }
  return 0;
}