/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time: 1092 ms                                         memory_used: 85.5 MB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ds[N+2];
set<pair<int,int> >adj[N+2];
vector<pair<int,int> >stop[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    for(int j=1;j<=x;j++)
    {
      int z;cin>>z;
      adj[i].insert({j,z});
      stop[z].push_back({i,j});
    }
  }
  for(int i=1;i<=n;i++)ds[i]=1e9;
  queue<int>q;q.push(1);ds[1]=0;
  while(q.size())
  {
    int p=q.front();q.pop();
    for(auto x:stop[p])
    {
      auto it=adj[x.first].find({x.second,p});
      if(it==adj[x.first].end())continue;
      auto on=it;
      while(true)
      {
        on++;if(on==adj[x.first].end())break;
        if(abs(on->first-it->first)<=k)
        {
          if(ds[on->second]>ds[p]+1)
          {
            ds[on->second]=ds[p]+1;
            q.push(on->second);
          }
        }
        else break;
      }
      on=it;
      while(true)
      {
        if(on==adj[x.first].begin())break;
        on--;
        if(abs(on->first-it->first)<=k)
        {
          if(ds[on->second]>ds[p]+1)
          {
            ds[on->second]=ds[p]+1;
            q.push(on->second);
          }
        }
        else break;
      }
      adj[x.first].erase(*it);
    }
      }
  cout<<ds[n]<<endl;
  return 0;
}