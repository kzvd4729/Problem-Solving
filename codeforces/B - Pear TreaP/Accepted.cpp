/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/01/2020 19:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 904 ms                                          memory_used: 31800 KB                             
*  problem: https://codeforces.com/gym/102787/problem/B
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
const int N=1e6,mod=1000001011,b=307;
int tr;
struct treap
{
  int lt,rt,dt,pri,sz;
  int frhs,rvhs;
}bst[N+2];
int pw[N+2];
void pre()
{
  pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(1LL*pw[i-1]*b)%mod;
}
void cal(int nd)
{
  if(nd==0)assert(0);
  int l=bst[nd].lt,r=bst[nd].rt;
  bst[nd].sz=bst[l].sz+bst[r].sz+1;
   bst[nd].frhs=(1LL*bst[l].frhs*b+bst[nd].dt)%mod;
  bst[nd].frhs=(1LL*bst[nd].frhs*pw[bst[r].sz]+bst[r].frhs)%mod;
   bst[nd].rvhs=(1LL*bst[r].rvhs*b+bst[nd].dt)%mod;
  bst[nd].rvhs=(1LL*bst[nd].rvhs*pw[bst[l].sz]+bst[l].rvhs)%mod;
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
  pre();int n,m;cin>>n>>m;
  string s;cin>>s;
   int root=0;
  for(int i=0;i<n;i++)
  {
    bst[++tr]={0,0,(int)s[i],rand(),1,(int)s[i],(int)s[i]};
    root=join(root,tr);
  }
  while(m--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int l,r;cin>>l>>r;
      pair<int,int>p1=splitbySize(root,l-1);
      pair<int,int>p2=splitbySize(p1.second,r-l+1);
      root=join(p1.first,p2.second);
    }
    else if(ty==2)
    {
      char c;int l;cin>>c>>l;
      pair<int,int>p=splitbySize(root,l-1);
      bst[++tr]={0,0,(int)c,rand(),1,(int)c,(int)c};
      root=join(p.first,tr);root=join(root,p.second);
    }
    else
    {
      int l,r;cin>>l>>r;
      pair<int,int>p1=splitbySize(root,l-1);
      pair<int,int>p2=splitbySize(p1.second,r-l+1);
       if(bst[p2.first].frhs==bst[p2.first].rvhs)cout<<"yes\n";
      else cout<<"no\n";
       root=join(p1.first,p2.first);root=join(root,p2.second);
    }
  }
  return 0;
}