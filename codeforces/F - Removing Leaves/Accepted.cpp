/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/17/2020 22:06                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 389 ms                                          memory_used: 60400 KB                             
*  problem: https://codeforces.com/contest/1385/problem/F
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
set<int>adj[N+2];
vector<int>lf[N+2];
int solve()
{
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)adj[i].clear(),lf[i].clear();
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].insert(v);adj[v].insert(u);
  }
  if(k==1)return n-1;
  for(int i=1;i<=n;i++)
  {
    if(adj[i].size()==1)
    {
      int nd=*adj[i].begin();
      lf[nd].push_back(i);
    }
  }
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)st.insert({lf[i].size(),i});
  int ans=0;
  while(true)
  {
    pair<int,int>p=*st.rbegin(); st.erase(p);
    if(p.first<k)return ans;ans++;
     int kk=k,nd=p.second;
    while(kk--)
    {
      if(lf[nd].size()==0)assert(0);
       int dl=lf[nd].back();lf[nd].pop_back();
      adj[nd].erase(dl);adj[dl].erase(nd);
    }
    st.insert({lf[nd].size(),nd});
    if(adj[nd].size()==1)
    {
      int rc=*adj[nd].begin();
       st.erase({lf[rc].size(),rc});
      lf[rc].push_back(nd);
      st.insert({lf[rc].size(),rc});
    }
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cout<<solve()<<endl;
  }
  return 0;
}