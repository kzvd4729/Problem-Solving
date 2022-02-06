/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/29/2019 17:55                        
*  solution_verdict: Runtime error on test 6                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 31500 KB                             
*  problem: https://codeforces.com/contest/1186/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
set<int>adj[N+2];
int dg[N+2],dl[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;set<pair<int,int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].insert(v);adj[v].insert(u);
    dg[u]++;dg[v]++;
    dl[u]=dg[u]/2;dl[v]=dg[v]/2;
    ed.insert({min(u,v),max(u,v)});
  }
  set<pair<pair<int,int>,int> >st;
  for(int i=1;i<=n;i++)
    st.insert({{(int)adj[i].size(),dl[i]},i});
  while(true)
  {
    if((int)ed.size()<=(n+m+1)/2)break;
    pair<pair<int,int>,int>p=*st.begin();
    if(p.first.first==0||p.first.second==0)
    {
      int nd=p.second;st.erase(p);
      for(auto x:adj[nd])
      {
        st.erase({{adj[x].size(),dl[x]},x});
        adj[x].erase(nd);
        st.insert({{adj[x].size(),dl[x]},x});
      }
      continue;
    }
    int u=p.second;
    int v=*adj[u].begin();
         st.erase({{adj[u].size(),dl[u]},u});
    adj[u].erase(v);dl[u]--;
    st.insert({{adj[u].size(),dl[u]},u});
     st.erase({{adj[v].size(),dl[v]},v});
    adj[v].erase(u);dl[v]--;
    st.insert({{adj[v].size(),dl[v]},v});
     ed.erase({min(u,v),max(u,v)});
    if(dl[u]<0||dl[v]<0)assert(0);
  }
  cout<<ed.size()<<endl;
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}