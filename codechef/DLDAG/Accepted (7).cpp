/****************************************************************************************
*  @author: kzvd4729                                         created: 14-12-2018 21:58:15                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.59 sec                                        memory_used: 117.1M                               
*  problem: https://www.codechef.com/DEC18A/problems/DLDAG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=1e6;
int out[N+2],sz[N+2],in[N+2];
vector<int>vc[N+2];set<int>adj[N+2];
set<pair<int,int> >pq,avl;
void add(int x)
{
  avl.insert({in[x],x});
  for(auto xx:vc[x])
  {
    pq.erase({sz[xx],xx});
    sz[xx]++;adj[xx].insert(x);
    pq.insert({sz[xx],xx});
  }
}
void del(int x)
{
  avl.erase({in[x],x});
  for(auto xx:vc[x])
  {
    pq.erase({sz[xx],xx});
    adj[xx].erase(x);sz[xx]--;
    out[xx]--;if(!out[xx])add(xx);
    pq.insert({sz[xx],xx});
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;vector<pair<int,int> >ed;
  while(m--)
  {
    int u,v;cin>>u>>v;
    ed.push_back({u,v});
    vc[v].push_back(u);
    out[u]++;in[v]++;
  }
  for(int i=1;i<=n;i++)
    if(!out[i])add(i);
  for(int i=1;i<=n;i++)
    pq.insert({sz[i],i});
  vector<vector<int> >ans;
  while(true)
  {
    pair<int,int>p=*pq.rbegin();
    if(p.first>=2)
    {
      int a=*adj[p.second].begin();adj[p.second].erase(a);
      int b=*adj[p.second].begin();adj[p.second].insert(a);
      del(a);del(b);ans.push_back({2,a,b});
    }
    else
    {
      if(avl.size()==0)break;
      if(avl.size()==1)
      {
        ans.push_back({1,avl.rbegin()->second});
        del(avl.rbegin()->second);
      }
      else
      {
        int a=avl.rbegin()->second;avl.erase({in[a],a});
        int b=avl.rbegin()->second;avl.insert({in[a],a});
        del(a);del(b);ans.push_back({2,a,b});
      }
    }
  }
  cout<<ans.size()<<endl;
  for(auto v:ans)
  {
    for(auto x:v)
      cout<<x<<" ";
    cout<<endl;
  }
  return 0;
}