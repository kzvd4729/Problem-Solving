/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/22/2018 23:30                        
*  solution_verdict: Wrong answer on pretest 7               language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1061/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;long x,y;cin>>n>>x>>y;set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    int u,v;cin>>u>>v;
    st.insert({u,v});
  }
  long ans=0;
  while(st.size())
  {
    pair<int,int>p=*st.begin();st.erase(p);
    ans=(ans+(x+y*(p.second-p.first))%mod)%mod;
    while(true)
    {
      auto xx=st.lower_bound({p.second+1,-mod});
      if(xx==st.end())break;
      long nw=x+y*(xx->second-xx->first);
      long od=y*(xx->second-p.second);
      if(od<=nw)
      {
        ans=(ans+od%mod)%mod;
        p={xx->first,xx->second};
        st.erase(p);
      }
      else break;
    }
  }
  cout<<ans<<endl;
  return 0;
}