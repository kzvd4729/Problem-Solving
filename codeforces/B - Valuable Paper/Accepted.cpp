/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/05/2020 19:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 217 ms                                          memory_used: 28500 KB                             
*  problem: https://codeforces.com/contest/1423/problem/B
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int a,b;//number of nodes in left and right side(both numbered from 1).
int lft[N+2],rgt[N+2],dis[N+2];vector<int>adj[N+2];
void clean()
{
  for(int i=1;i<=a;i++)lft[i]=0,adj[i].clear();
  for(int i=1;i<=b;i++)rgt[i]=0;
}
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=a;i++)
  {
    if(!lft[i])q.push(i),dis[i]=0;else dis[i]=inf;
  }
  dis[0]=inf;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto v:adj[u])
    {
      if(dis[rgt[v]]<=dis[u]+1)continue;//keeping distance only for left side
      dis[rgt[v]]=dis[u]+1;if(rgt[v])q.push(rgt[v]);
    }
  }
  return dis[0]!=inf;
}
bool dfs(int u)
{
  if(!u)return true;
  for(auto v:adj[u])
  {
    if(dis[u]+1==dis[rgt[v]])
    {
      if(dfs(rgt[v])){lft[u]=v;rgt[v]=u;return true;}
    }
  }
  return false;
}
int hopkroft(void)
{
  int match=0;
  while(bfs())
  {
    for(int i=1;i<=a;i++)
    {
      if(dis[i])continue;if(dfs(i))match++;
    }
  }
  return match;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;vector<vector<int> >vc;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    vc.push_back({w,u,v});
  }
  sort(vc.begin(),vc.end());
  int lo=0,hi=vc.size(),md;a=n,b=n;
  while(lo<hi)
  {
    md=(lo+hi)/2;
    for(int i=0;i<=md;i++)adj[vc[i][1]].push_back(vc[i][2]);
     if(hopkroft()==n)hi=md;else lo=md+1;
    clean();
  }
  if(lo==vc.size())cout<<-1<<endl;
  else cout<<vc[lo][0]<<endl;
    return 0;
}