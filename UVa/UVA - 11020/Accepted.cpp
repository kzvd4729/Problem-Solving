/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 15:42:59                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 40                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11020
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
set<pair<int,int> >st;
map<pair<int,int>,int>mp;
vector<pair<int,int> >del;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0,f=0;cin>>t;
  while(t--)
  {
    int n,ans=0;cin>>n;st.clear(),mp.clear();
    if(f)cout<<"\n";f=1;
    cout<<"Case #"<<++tc<<":\n";
    while(n--)
    {
      del.clear();
      int u,v;cin>>u>>v;
      if((int)st.size()==0)
      {
        st.insert({u,v}),mp[{u,v}]++;
        ans++;cout<<ans<<"\n";
        continue;
      }
      auto it=st.lower_bound(make_pair(u,-1));

      if(it!=st.end())
      {
        if(it->first==u&&it->second==v)
        {
          mp[{u,v}]++;ans++;
          cout<<ans<<"\n";continue;
        }
      }
      if(it!=st.end())
      {
        if(it->first==u&&it->second<v)
        {
          cout<<ans<<"\n";continue;
        }
      }
      if(it!=st.begin())
      {
        auto pr=it;pr--;
        if(pr->second<=v)
        {
          cout<<ans<<"\n";continue;
        }
      }
      while(it!=st.end())
      {
        if((it->first>=u&&it->second>v)||(it->first>u&&it->second>=v))
          del.push_back(*it);
        else break;it++;
      }
      for(auto x:del)
      {
        st.erase(x),ans-=mp[x];mp[x]=0;
      }
      st.insert({u,v});mp[{u,v}]++;ans++;
      cout<<ans<<"\n";
    }
  }
  return 0;
}