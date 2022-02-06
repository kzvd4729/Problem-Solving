/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/29/2019 16:31                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 1575 ms                                         memory_used: 117700 KB                            
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
    st.insert({{dl[i],(int)adj[i].size()},i});
  while(true)
  {
    while(st.size())
    {
      pair<pair<int,int>,int>p=*st.begin();
      //cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl;
      //getchar();
      if(p.first.first)break;
      int nd=p.second;st.erase(p);
      for(auto x:adj[nd])
      {
        st.erase({{dl[x],adj[x].size()},x});
        adj[x].erase(nd);
        st.insert({{dl[x],adj[x].size()},x});
      }
    }
    /*cout<<endl<<endl;
    for(auto x:st)
    {
      cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
    }
    cout<<endl<<endl;*/
    pair<pair<int,int>,int>p=*st.begin();
    int u=p.second;
    if(adj[u].size()==0)assert(0);
    int v=*adj[u].begin();
     st.erase({{dl[u],adj[u].size()},u});
    adj[u].erase(v);dl[u]--;
    st.insert({{dl[u],adj[u].size()},u});
     st.erase({{dl[v],adj[v].size()},v});
    adj[v].erase(u);dl[v]--;
    st.insert({{dl[v],adj[v].size()},v});
     ed.erase({min(u,v),max(u,v)});
    if((int)ed.size()<=(n+m+1)/2)break;
  }
  //cout<<endl;
  cout<<ed.size()<<endl;
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}