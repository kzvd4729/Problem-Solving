/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/22/2019 01:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1154 ms                                         memory_used: 22600 KB                             
*  problem: https://codeforces.com/contest/1257/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
 map<vector<int>,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int tt=(1<<30)-1,a,b;b=tt;
  for(int i=0;i<15;i++)b^=(1<<i);a=b^tt;
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;aa[i]=x&a;
    for(int j=15;j<30;j++)
      if(x&(1<<j))bb[i]|=(1<<(j-15));
   }
  for(int i=0;i<(1<<15);i++)
  {
    vector<int>v;
    for(int j=1;j<=n;j++)
      v.push_back(__builtin_popcount((i^bb[j])));
    mp[v]=i;
  }
  for(int i=0;i<(1<<15);i++)
  {
    int mx=0;vector<int>now;
    for(int j=1;j<=n;j++)
    {
      mx=max(mx,__builtin_popcount((i^aa[j])));
      now.push_back(__builtin_popcount((i^aa[j])));
    }
    for(int m=mx;m<=30;m++)
    {
      vector<int>v;
      for(auto x:now)
        v.push_back(m-x);
      if(mp.find(v)!=mp.end())
      {
        auto it=mp.find(v);
        int ans=i;
        for(int p=0;p<15;p++)
        {
          if((it->second&(1<<p)))
            ans|=(1<<(15+p));
        }
        cout<<ans<<endl,exit(0);
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}