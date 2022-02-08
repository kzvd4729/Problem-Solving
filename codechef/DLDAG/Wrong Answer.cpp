/****************************************************************************************
*  @author: kzvd4729                                         created: 14-12-2018 19:56:59                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 91.2M                                
*  problem: https://www.codechef.com/DEC18A/problems/DLDAG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=1e6;
int out[N+2],sz[N+2];
vector<int>vc[N+2];set<int>adj[N+2],dl;
set<pair<int,int> >pq;
void add(int x)
{
  //cout<<"add "<<x<<endl;
  for(auto xx:vc[x])
  {
    pq.erase({sz[xx],xx});
    sz[xx]++;adj[xx].insert(x);
    pq.insert({sz[xx],xx});
  }
}
void del(int x)
{
  dl.erase(x);
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
  while(pq.size())
  {
    pair<int,int>p=*pq.rbegin();
    if(!p.first)break;
    if(p.first>=2)
    {
      int a=*adj[p.second].begin();adj[p.second].erase(a);
      int b=*adj[p.second].begin();adj[p.second].insert(a);
      del(a);del(b);cout<<2<<" "<<a<<" "<<b<<endl;
    }
    else
    {
      int a=*adj[p.second].begin();int f=0;
      if(pq.size())
      {
        pq.erase(p);
        pair<int,int>pp=*pq.rbegin();
        pq.insert(p);
        if(pp.first)
        {
          int b=*adj[pp.second].begin();
          del(a);del(b);cout<<2<<" "<<a<<" "<<b<<endl;
          f=1;
        }
      }
      if(!f)
      {
        cout<<1<<" "<<a<<endl;
        del(a);
      }
    }
  }
  while(dl.size())
  {
    int a=*dl.begin();dl.erase(a);
    if(dl.size())
    {
      int b=*dl.begin();dl.erase(b);
      cout<<2<<" "<<a<<" "<<b<<endl;
    }
    else cout<<1<<" "<<a<<endl;
  }
  return 0;
}