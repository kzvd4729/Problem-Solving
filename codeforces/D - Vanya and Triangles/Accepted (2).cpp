/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/01/2018 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1450 ms                                         memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/552/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
pair<int,int>pp[N+2];
struct _hash{
  size_t operator()(const pair<int,int>&x)const
  {
    return ((long)x.first)^(((long)x.second)<<32);
  }
};
unordered_map<pair<int,int>,int,_hash>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long ans=0;
  for(int i=1;i<=n;i++)
    cin>>pp[i].first>>pp[i].second;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j)continue;
      pair<int,int>p=pp[j];
      p.first-=pp[i].first;p.second-=pp[i].second;
      int gcd=__gcd(abs(p.first),abs(p.second));
      p.first/=gcd;p.second/=gcd;
      if(mp[{p.first*-1,p.second*-1}])mp[{p.first*-1,p.second*-1}]++;
      else mp[{p.first,p.second}]++;
    }
    for(auto x:mp)
      ans+=((x.second*1LL)*(n-x.second-1));
    mp.clear();
  }
  cout<<ans/6<<endl;
  return 0;
}