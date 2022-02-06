/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/27/2020 21:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 826 ms                                          memory_used: 35900 KB                             
*  problem: https://codeforces.com/contest/1282/problem/E
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
const int N=1e5;
int n;
map<vector<int>,int>mp;
set<int>adj[N+2];
vector<int>ord,cy[N+2],pr;
void upd(int i,int j,int k)
{
  if(i>j)swap(i,j);if(i>k)swap(i,k);
  if(j>k)swap(j,k);ord.push_back(mp[{i,j,k}]);
}
void dfs(int node,int par)
{
  if(pr.size()==n)return;
  pr.push_back(node);
  for(auto x:cy[node])
    if(x!=par)dfs(x,node);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;mp.clear(),ord.clear(),pr.clear();
    for(int i=1;i<=n;i++)adj[i].clear(),cy[i].clear();
    for(int i=1;i<=n-2;i++)
    {
      int a,b,c;cin>>a>>b>>c;
      if(a>b)swap(a,b);if(a>c)swap(a,c);
      if(b>c)swap(b,c);mp[{a,b,c}]=i;
       adj[a].insert(b);adj[b].insert(a);
      adj[a].insert(c);adj[c].insert(a);
      adj[b].insert(c);adj[c].insert(b);
    }
    set<pair<int,int> >st,no;
    for(int i=1;i<=n;i++)st.insert({adj[i].size(),i});
     /*for(int i=1;i<=n;i++)
    {
      cout<<i<<" ";
      for(auto x:adj[i])cout<<x<<" ";cout<<endl;
    }*/
        while(st.size())
    {
      pair<int,int>p=*st.begin();if(p.first!=2)break;st.erase(p);
      int node=p.second;//cout<<node<<endl;
      int a=*adj[node].begin(),b=*adj[node].rbegin();adj[node].clear();
       st.erase({adj[a].size(),a});st.erase({adj[b].size(),b});
       if(no.find({node,a})==no.end())
      {
        //cout<<node<<" "<<a<<endl;
        cy[node].push_back(a),cy[a].push_back(node);
      }
      if(no.find({node,b})==no.end())
      {
        //cout<<node<<" "<<b<<endl;
        cy[node].push_back(b),cy[b].push_back(node);
      }
       no.insert({a,b});no.insert({b,a});
       if(adj[a].find(node)!=adj[a].end())adj[a].erase(node);
      if(adj[b].find(node)!=adj[b].end())adj[b].erase(node);
       if(adj[a].size())st.insert({adj[a].size(),a});
      if(adj[b].size())st.insert({adj[b].size(),b});
       upd(node,a,b);
    }
    int node=1;
    for(int i=1;i<=n;i++)if(cy[i].size()==1)node=i;
    dfs(node,-1);//cout<<pr.size()<<endl;
    for(int i=0;i<pr.size();i++)cout<<pr[i]<<" ";cout<<endl;
    for(int i=0;i<ord.size();i++)cout<<ord[i]<<" ";cout<<endl;
  }
  return 0;
}