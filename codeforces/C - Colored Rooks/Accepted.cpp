/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/24/2018 23:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 2500 KB                              
*  problem: https://codeforces.com/contest/1068/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
vector<int>adj[N+2];
vector<pair<int,int> >color[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;if(u>v)swap(u,v);
    adj[u].push_back(v);
  }
  for(int i=1;i<=n;i++)
    color[i].push_back({i,i});
  int row=n;
  for(int i=1;i<=n;i++)
  {
    for(auto x:adj[i])
    {
      row++;
      color[i].push_back({i,row});
      color[x].push_back({x,row});
    }
  }
  for(int i=1;i<=n;i++)
  {
    cout<<color[i].size()<<endl;
    for(auto x:color[i])
    {
      cout<<x.first<<" "<<x.second<<endl;
    }
  }
  return 0;
}