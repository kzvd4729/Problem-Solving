/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/06/2019 17:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/412/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;set<pair<int,int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    ed.insert({u,v});
  }
  vector<int>v;v.push_back(1);
  for(int i=2;i<=n;i++)
  {
    v.push_back(i);
    int pt=v.size()-1;
    while(true)
    {
      if(!pt)break;
      if(ed.find({v[pt-1],v[pt]})!=ed.end())
        swap(v[pt-1],v[pt]),pt--;
      else break;
    }
  }
  for(auto x:v)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}