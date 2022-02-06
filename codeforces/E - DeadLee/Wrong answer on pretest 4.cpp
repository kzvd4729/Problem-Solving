/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/23/2020 22:02                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 31200 KB                             
*  problem: https://codeforces.com/contest/1369/problem/E
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
int a[N+2];
set<pair<int,int> >adj[N+2];
void dead(){cout<<"DEAD"<<endl,exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  set<pair<int,int> >st;
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i],st.insert({a[i],i});
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].insert({v,i});adj[v].insert({u,i});
  }
  vector<int>ord;
  while(st.size())
  {
    pair<int,int>p=*st.begin();st.erase(p);
    while(true)
    {
      if(adj[p.second].size()==0)break;
       pair<int,int>tmp=*adj[p.second].begin();
      adj[p.second].erase(tmp);
       int f=tmp.second;ord.push_back(f);
      adj[tmp.first].erase({p.second,f});
       if(a[tmp.first]==0)dead();
       st.erase({a[tmp.first],tmp.first});
      a[tmp.first]--;st.insert({a[tmp.first],tmp.first});
    }
  }
  if(ord.size()!=m)dead();
  cout<<"ALIVE"<<endl;
  for(auto x:ord)cout<<x<<" ";cout<<endl;
  return 0;
}