/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 22:20:16                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-1160
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int par[N+2];
int get(int x)
{
  if(par[x]==x)return x;
  return par[x]=get(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int u,v;vector<pair<int,int> >ed;
  while(cin>>u)
  {
    if(u==-1)continue;ed.clear();
    cin>>v;ed.push_back({u,v});
    while(cin>>u)
    {
      if(u==-1)break;
      cin>>v;ed.push_back({u,v});
    }
    for(int i=0;i<=N;i++)par[i]=i;
    int cnt=0;
    for(auto x:ed)
    {
      int r1=get(x.first),r2=get(x.second);
      if(r1==r2)cnt++;
      else par[r1]=r2;
    }
    cout<<cnt<<endl;
  }
  return 0;
}