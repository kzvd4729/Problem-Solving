/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/01/2020 18:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1450 ms                                         memory_used: 19600 KB                             
*  problem: https://codeforces.com/gym/102787/problem/A
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
}bst[N+2];
void cal(int node)
{
  bst[node].sz=bst[bst[node].lt].sz+bst[bst[node].rt].sz+1;
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
   int n;cin>>n;int root=0;
  for(int i=1;i<=n;i++)
  {
    bst[++tr]={0,0,i,rand(),1};
    root=join(root,tr);
  }
  for(int i=1;i<=n;i++)
  {
    int a,b;cin>>a>>b;
    int l=min(b-a,n-b+1);if(l<=0)continue;
    pair<int,int>p1=splitbySize(root,a-1);
    pair<int,int>p2=splitbySize(p1.second,l);
    pair<int,int>p3=splitbySize(p2.second,b-a-l);
    pair<int,int>p4=splitbySize(p3.second,l);
     root=p1.first;root=join(root,p4.first);
    root=join(root,p3.first);root=join(root,p2.first);
    root=join(root,p4.second);
  }
  for(int i=1;i<=n;i++)
  {
    pair<int,int>p=splitbySize(root,1);
    cout<<bst[p.first].dt<<" ";root=p.second;
  }
  cout<<endl;
  return 0;
}