/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2020 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 75900 KB                             
*  problem: https://codeforces.com/contest/1242/problem/B
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
const int N=1e6;
int vs[3000+2][3000+2],par[N+2];
int find(int x)
{
  if(x==par[x])return x;
  return par[x]=find(par[x]);
}
void solve1(int n,int m)
{
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;if(u>v)swap(u,v);
    vs[u][v]=1;
  }
  for(int i=1;i<=n;i++)par[i]=i;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(vs[i][j])continue;
      int a=find(i),b=find(j);
      if(a==b)continue;
      par[a]=b;
    }
  }
  set<int>st;
  for(int i=1;i<=n;i++)st.insert(find(i));
  cout<<st.size()-1<<endl;
}
set<int>st[N+2];
void solve2(int n,int m)
{
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    st[u].insert(v);st[v].insert(u);
  }
  int mn=n,nd;
  for(int i=1;i<=n;i++)
  {
    if(st[i].size()<mn)mn=st[i].size(),nd=i;
  }
  set<int>rm;
  for(int i=1;i<=n;i++)rm.insert(i);
  rm.erase(nd);
  for(int i=1;i<=n;i++)if(st[nd].find(i)==st[nd].end())rm.erase(i);
   for(int x=1;x<=n;x++)
  {
    if(st[nd].find(x)!=st[nd].end())continue;
    vector<int>dl;
    for(auto z:rm)
    {
      if(st[x].find(z)==st[x].end())dl.push_back(z);
    }
    for(auto z:dl)rm.erase(z);
  }
  int ans=0;
  while(rm.size())
  {
    int b=*rm.begin();rm.erase(b);ans++;
    vector<int>dl;
    for(auto x:rm)
    {
      if(st[b].find(x)==st[b].end())dl.push_back(x);
    }
    for(auto x:dl)rm.erase(x);
  }
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  if(n<=3000)solve1(n,m);
  else solve2(n,m);
    return 0;
}