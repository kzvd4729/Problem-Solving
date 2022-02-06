/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/16/2021 21:26                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 124 ms                                          memory_used: 11100 KB                             
*  problem: https://codeforces.com/contest/1490/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    vector<pair<long,long> >v;v.push_back({0,0});
    long bl=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      bl+=x;if(bl>v.back().first)v.push_back({bl,i});
    }
    long mx=v.back().first;
    while(m--)
    {
      long x;cin>>x;
       if(mx==0)
      {
        cout<<-1<<" ";continue;
      }
      if(mx>=x)
      {
        int id=lower_bound(v.begin(),v.end(),make_pair(x,-1LL))-v.begin();
        cout<<v[id].second-1<<" ";
        continue;
      }
      if(bl<=0)
      {
        cout<<-1<<" ";continue;
      }
      long df=x-mx;
      long dv=(df+bl-1)/bl;
      long ans=0;
       ans+=n*dv;
      x-=bl*dv;
      int id=lower_bound(v.begin(),v.end(),make_pair(x,-1LL))-v.begin();
      cout<<ans+v[id].second-1<<" ";
    }
    cout<<'\n';
  }
  return 0;
}