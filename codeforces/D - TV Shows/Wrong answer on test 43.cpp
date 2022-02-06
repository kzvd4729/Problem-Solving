/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/22/2018 23:40                        
*  solution_verdict: Wrong answer on test 43                 language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1061/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n;long x,y;cin>>n>>x>>y;multiset<pair<long,long> >st;
  for(long i=1;i<=n;i++)
  {
    long u,v;cin>>u>>v;
    st.insert({u,v});
  }
  long ans=0;
  while(st.size())
  {
    pair<long,long>p=*st.begin();st.erase(st.find(p));
    ans=(ans+(x+y*(p.second-p.first))%mod)%mod;
    while(st.size())
    {
      auto xx=st.lower_bound({p.second+1,-mod});
      if(xx==st.end())break;
      long nw=x+y*(xx->second-xx->first);
      long od=y*(xx->second-p.second);
      if(od<=nw)
      {
        ans=(ans+od%mod)%mod;
        p={xx->first,xx->second};
        st.erase(st.find(p));
      }
      else break;
    }
  }
  cout<<ans%mod<<endl;
  return 0;
}