/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2018 15:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/25/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,u,v,parent[N+2];
vector<pair<int,int> >ed;
int union_find(int node)
{
  if(node==parent[node])return node;
  return parent[node]=union_find(parent[node]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=N;i++)parent[i]=i;
  for(int i=1;i<n;i++)
  {
    cin>>u>>v;
    int uu=union_find(u);
    int vv=union_find(v);
    if(uu!=vv)
      parent[uu]=vv;
    else ed.push_back({u,v});
  }
  cout<<ed.size()<<endl;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      int ii=union_find(i);
      int jj=union_find(j);
      if(ii==jj)continue;
      parent[ii]=jj;
      cout<<ed[ed.size()-1].first<<" "<<ed[ed.size()-1].second<<" "<<i<<" "<<j<<"\n";
      ed.pop_back();
    }
  }
  return 0;
}