/****************************************************************************************
*  @author: kzvd4729                                         created: 14-12-2018 21:42:31                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.83 sec                                        memory_used: 123.6M                               
*  problem: https://www.codechef.com/DEC18A/problems/DLDAG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=1e6;
int out[N+2],sz[N+2];
vector<int>vc[N+2];set<int>adj[N+2],dl,avl;
set<pair<int,int> >pq;
void add(int x)
{
  //cout<<"add "<<x<<endl;
  avl.insert(x);
  for(auto xx:vc[x])
  {
    pq.erase({sz[xx],xx});
    sz[xx]++;adj[xx].insert(x);
    pq.insert({sz[xx],xx});
  }
}
void del(int x)
{
  //if(dl.find(x)==dl.end())assert(0);
  dl.erase(x);avl.erase(x);
  //cout<<"del "<<x<<endl;
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
  for(int i=1;i<=n;i++)dl.insert(i);
  while(m--)
  {
    int u,v;cin>>u>>v;
    ed.push_back({u,v});
    vc[v].push_back(u);
    out[u]++;
  }
  for(int i=1;i<=n;i++)
    if(!out[i])avl.insert(i);
  for(auto x:ed)
  {
    if(out[x.second])continue;
    adj[x.first].insert(x.second);
    sz[x.first]++;
  }
  for(int i=1;i<=n;i++)
  {
    pq.insert({sz[i],i});
    //cout<<out[i]<<endl;
  }
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
        ans.push_back({1,*avl.rbegin()});
        del(*avl.rbegin());
      }
      else
      {
        int a=*avl.rbegin();avl.erase(a);
        int b=*avl.rbegin();avl.insert(a);
        del(a);del(b);ans.push_back({2,a,b});
      }
    }
  }
  // while(dl.size())
  // {
  //   int a=*dl.begin();dl.erase(a);
  //   if(dl.size())
  //   {
  //     int b=*dl.begin();dl.erase(b);
  //     ans.push_back({2,a,b});
  //   }
  //   else ans.push_back({1,a});
  // }
  cout<<ans.size()<<endl;
  for(auto v:ans)
  {
    for(auto x:v)
      cout<<x<<" ";
    cout<<endl;
  }
  return 0;
}