/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/07/2020 12:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1357 ms                                         memory_used: 32700 KB                             
*  problem: https://codeforces.com/contest/796/problem/C
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
vector<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  set<pair<int,int> >st;int ans=2e9;
  for(int i=1;i<=n;i++)st.insert({aa[i],i});
  for(int i=1;i<=n;i++)
  {
    int now;
    st.erase({aa[i],i});now=aa[i];
    for(auto x:adj[i])
    {
      st.erase({aa[x],x});now=max(now,aa[x]+1);
    }
    if(st.size())now=max(now,st.rbegin()->first+2);
    st.insert({aa[i],i});
    for(auto x:adj[i])st.insert({aa[x],x});
    ans=min(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}