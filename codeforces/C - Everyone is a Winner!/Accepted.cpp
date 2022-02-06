/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/29/2019 21:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 217 ms                                          memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/1263/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int lo=1,hi=n,md;vector<int>v;
    while(lo<=n)
    {
      hi=n;v.push_back(n/lo);
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(n/lo==n/md)lo=md;else hi=md;
      }
      for(md=lo;md<=hi;md++)
        if(n/lo!=n/md)break;
      lo=md;
    }
    v.push_back(0);
     sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(auto x:v)cout<<x<<" ";
      cout<<endl;
  }
    return 0;
}