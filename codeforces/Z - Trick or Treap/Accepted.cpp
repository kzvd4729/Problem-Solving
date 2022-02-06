/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2020 13:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 404 ms                                          memory_used: 31300 KB                             
*  problem: https://codeforces.com/gym/102787/problem/Z
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
const int N=1e6;
int tr;
struct treap
{
  int lt,rt,dt,pri,sz;
  int pr;long sm;
}bst[N+2];
void cal(int nd)
{
  int l=bst[nd].lt,r=bst[nd].rt;
  bst[nd].sz=bst[l].sz+bst[r].sz+1;
  bst[nd].sm=bst[l].sm+bst[r].sm+bst[nd].dt;
   if(l)bst[l].pr=nd;if(r)bst[r].pr=nd;
  bst[nd].pr=0;
}
int find(int nd)
{
  if(bst[nd].pr==0)return nd;
  return find(bst[nd].pr);
}
pair<int,int>splitbySize(int node,int ss)
{
  if(!node)return {0,0};pair<int,int>p;
  if(bst[bst[node].lt].sz>=ss)
  {
    p=splitbySize(bst[node].lt,ss);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
  else
  {
    p=splitbySize(bst[node].rt,ss-bst[bst[node].lt].sz-1);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
}
int join(int lt,int rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(bst[lt].pri>=bst[rt].pri)
  {
    bst[lt].rt=join(bst[lt].rt,rt);
    cal(lt);return lt;
  }
  else
  {
    bst[rt].lt=join(lt,bst[rt].lt);
    cal(rt);return rt;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int y;cin>>y;
      bst[i]={0,0,y,rand(),1,0,y};
    }
    else if(ty==2)
    {
      int y,z;cin>>y>>z;
      if(find(y)==find(z))continue;
      join(find(y),find(z));
    }
    else if(ty==3)
    {
      int y,z;cin>>y>>z;
      if(bst[find(y)].sz>z)splitbySize(find(y),z);
    }
    else
    {
      int y;cin>>y;
      cout<<bst[find(y)].sm<<'\n';
    }
  }
  return 0;
}