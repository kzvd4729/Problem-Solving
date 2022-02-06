/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/01/2020 20:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 498 ms                                          memory_used: 43300 KB                             
*  problem: https://codeforces.com/gym/102787/problem/Y
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
  int lz,lzr,rzr,lon,ron,mx;
}bst[N+2];
void tooLazy(int nd)
{
  if(nd==0||bst[nd].lz==0)return ;
  bst[nd].dt^=1;
  swap(bst[nd].lzr,bst[nd].lon);
  swap(bst[nd].rzr,bst[nd].ron);
   int l=bst[nd].lt,r=bst[nd].rt;
  if(l)bst[l].lz^=1;if(r)bst[r].lz^=1;
   bst[nd].lz=0;
}
void cal(int nd)
{
  int l=bst[nd].lt,r=bst[nd].rt;
  bst[nd].sz=bst[l].sz+bst[r].sz+1;
   tooLazy(nd);tooLazy(l);tooLazy(r);
   bst[nd].lzr=bst[l].lzr;
  if(bst[nd].dt==0&&bst[l].lzr==bst[l].sz)bst[nd].lzr+=1+bst[r].lzr;
   bst[nd].lon=bst[l].lon;
  if(bst[nd].dt==1&&bst[l].lon==bst[l].sz)bst[nd].lon+=1+bst[r].lon;
   bst[nd].rzr=bst[r].rzr;
  if(bst[nd].dt==0&&bst[r].rzr==bst[r].sz)bst[nd].rzr+=1+bst[l].rzr;
   bst[nd].ron=bst[r].ron;
  if(bst[nd].dt==1&&bst[r].ron==bst[r].sz)bst[nd].ron+=1+bst[l].ron;
   bst[nd].mx=1;
  bst[nd].mx=max(bst[nd].mx,bst[l].mx);
  bst[nd].mx=max(bst[nd].mx,bst[r].mx);
  if(bst[nd].dt==0)bst[nd].mx=max(bst[nd].mx,bst[l].rzr+1+bst[r].lzr);
  if(bst[nd].dt==1)bst[nd].mx=max(bst[nd].mx,bst[l].ron+1+bst[r].lon);
}
pair<int,int>splitbySize(int node,int ss)
{
  tooLazy(node);
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
  tooLazy(lt);tooLazy(rt);
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
  int n,q;cin>>n>>q;string s;cin>>s;
  int root=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='0')bst[++tr]={0,0,0,rand(),1,0,1,1,0,0,1};
    else bst[++tr]={0,0,1,rand(),1,0,0,0,1,1,1};
    root=join(root,tr);
  }
  while(q--)
  {
    int ty,l,r;cin>>ty>>l>>r;
    pair<int,int>p1=splitbySize(root,l-1);
    pair<int,int>p2=splitbySize(p1.second,r-l+1);
    bst[p2.first].lz^=1;
     root=join(p1.first,p2.first);root=join(root,p2.second);
    cout<<bst[root].mx<<'\n';
     /*for(int i=1;i<=n;i++)
    {
      pair<int,int>p1=splitbySize(root,i-1);
      pair<int,int>p2=splitbySize(p1.second,1);
      cout<<bst[p2.first].dt;
      root=join(p1.first,p2.first);root=join(root,p2.second);
    }
    cout<<endl;*/
  }
  return 0;
}