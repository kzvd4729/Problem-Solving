/****************************************************************************************
*  @author: kzvd4729                                         created: May/03/2020 10:48                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/521/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+9;
vector<int>adj[N+2];int in[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  map<pair<int,int>,int>mp;
  int n;cin>>n;vector<pair<int,int> >ed;
  for(int i=0;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ed.push_back({u,v});
    mp[{u,v}]=i;
  }
  for(auto x:ed)
  {
    if(mp.count({x.first-1,x.second-1}))
      adj[mp[x]].push_back(mp[{x.first-1,x.second-1}]);
    if(mp.count({x.first,x.second-1}))
      adj[mp[x]].push_back(mp[{x.first,x.second-1}]);
    if(mp.count({x.first+1,x.second-1}))
      adj[mp[x]].push_back(mp[{x.first+1,x.second-1}]);
  }
  for(int i=0;i<n;i++)
    for(auto x:adj[i])in[x]++;
  set<pair<int,int> >st;
  for(int i=0;i<n;i++)st.insert({in[i],i});
  set<int>fr;int ans=0;
  for(int i=1;i<=n;i++)
  {
    while(st.size())
    {
      pair<int,int>p=*st.begin();
      if(p.first)break;
       st.erase(p);fr.insert(p.second);
    }
    int tr=*fr.begin();if(i%2)tr=*fr.rbegin();
    fr.erase(tr);
     ans=(1LL*ans*n+tr)%mod;
    for(auto x:adj[tr])
    {
      st.erase({in[x],x});
      in[x]--;st.insert({in[x],x});
    }
  }
  cout<<ans<<endl;
  return 0;
}