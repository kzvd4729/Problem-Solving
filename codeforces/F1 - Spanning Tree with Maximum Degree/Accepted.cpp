/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/07/2019 22:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 26200 KB                             
*  problem: https://codeforces.com/contest/1133/problem/F1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int par[N+2];
vector<int>adj[N+2];
int _find(int x)
{
  if(x==par[x])return x;
  return par[x]=_find(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int mx=-1,nd=-1;
  for(int i=1;i<=n;i++)
  {
    //cout<<adj[i].size()<<endl;
    if((int)adj[i].size()>mx)
    {
      mx=(int)adj[i].size();
      nd=i;
    }
  }
  for(int i=1;i<=n;i++)par[i]=i;
  vector<pair<int,int> >ed;
  //cout<<mx<<" "<<nd<<endl;
  for(auto x:adj[nd])
  {
    int r1=_find(nd);
    int r2=_find(x);
    if(r1==r2)continue;
    par[r1]=r2;ed.push_back({nd,x});
  }
  for(int i=1;i<=n;i++)
  {
    nd=i;
    for(auto x:adj[nd])
    {
      int r1=_find(nd);
      int r2=_find(x);
      if(r1==r2)continue;
      par[r1]=r2;ed.push_back({nd,x});
    }
  }
  //cout<<endl;
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}