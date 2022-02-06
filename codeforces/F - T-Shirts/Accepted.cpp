/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/08/2020 19:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 982 ms                                          memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/702/problem/F
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
const int N=2e5;
pair<int,int>pp[N+2],kk[N+2];
int tr;
struct treap
{
  int lt,rt,dt,pri,lz,ad,ld,mx,mn,id;
}bst[N+2];
void tooLazy(int node)
{
  if(node==0)return;
  int sb=bst[node].lz;
  bst[node].dt-=sb,bst[node].mx-=sb,bst[node].mn-=sb;
  //assert(bst[node].dt>=0&&bst[node].mn>=0);
  //cout<<"*"<<bst[node].mn<<endl;
  bst[node].ad+=bst[node].ld;
   int l=bst[node].lt;
  bst[l].lz+=sb,bst[l].ld+=bst[node].ld;
   int r=bst[node].rt;
  bst[r].lz+=sb,bst[r].ld+=bst[node].ld;
   bst[node].lz=0,bst[node].ld=0;
}
void cal(int node)
{
  if(node==0)return;
  tooLazy(node);
  int l=bst[node].lt,r=bst[node].rt;tooLazy(l),tooLazy(r);
  bst[node].mx=max({bst[node].dt,bst[l].mx,bst[r].mx});
  bst[node].mn=min({bst[node].dt,bst[l].mn,bst[r].mn});
}
//left tree will contain value <= vl.
pair<int,int>splitbyValue(int node,int vl)
{
  if(!node)return {0,0};pair<int,int>p;
  tooLazy(node);
  if(bst[node].lt)tooLazy(bst[node].lt);
  if(bst[node].rt)tooLazy(bst[node].rt);
  if(bst[node].dt<=vl)
  {
    p=splitbyValue(bst[node].rt,vl);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
  else
  {
    p=splitbyValue(bst[node].lt,vl);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
}
//maximum element of left tree <= minimum element of right tree
int join(int lt,int rt)
{
  if(lt)tooLazy(lt);if(rt)tooLazy(rt);
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
//lt and rt are bst and sorted sequence;
int join2(int lt,int rt)
{
  if(lt)tooLazy(lt);if(rt)tooLazy(rt);
  if(bst[lt].mx<=bst[rt].mn)return join(lt,rt);
  if(bst[rt].mx<=bst[lt].mn)return join(rt,lt);
  if(bst[lt].pri>=bst[rt].pri)
  {
    pair<int,int>p=splitbyValue(rt,bst[lt].dt);
    bst[lt].lt=join2(p.first,bst[lt].lt);
    bst[lt].rt=join2(p.second,bst[lt].rt);
    cal(lt);return lt;
  }
  else
  {
    pair<int,int>p=splitbyValue(lt,bst[rt].dt);
    bst[rt].lt=join2(p.first,bst[rt].lt);
    bst[rt].rt=join2(p.second,bst[rt].rt);
    cal(rt);return rt;
  }
}
int ans[N+2];
void dfs(int node)
{
  if(!node)return;tooLazy(node);
  //cout<<bst[node].id<<endl;
  ans[bst[node].id]=bst[node].ad;
  dfs(bst[node].lt);dfs(bst[node].rt);
}
void trv(int node)
{
  if(!node)return;tooLazy(node);
  //cout<<bst[node].id<<endl;
  //ans[bst[node].id]=bst[node].ad;
  trv(bst[node].lt);cout<<bst[node].dt<<" ";
  trv(bst[node].rt);
  //cout<<bst[node].dt<<" ";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>pp[i].first>>pp[i].second;
   sort(pp+1,pp+n+1,[&](pair<int,int>a,pair<int,int>b){
    if(a.second==b.second)return a.first<b.first;
    return a.second>b.second;
  });
  int k;cin>>k;
  for(int i=1;i<=k;i++)cin>>kk[i].first,kk[i].second=i;
  sort(kk+1,kk+k+1,[&](pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
  });
  //int lt,rt,dt,pri,lz,ad,ld,mx,mn,id;
  int root=0;
  bst[0]={0,0,0,0,0,0,0,0,1000000001,0};
  for(int i=1;i<=k;i++)
  {
    bst[++tr]={0,0,kk[i].first,rand(),0,0,0,kk[i].first,kk[i].first,kk[i].second};
    root=join2(root,tr);
  }
  //cout<<"--> ";trv(root);cout<<endl;
  for(int i=1;i<=n;i++)
  {
    pair<int,int>p=splitbyValue(root,pp[i].first-1);
    //cout<<p.second<<endl;
    bst[p.second].ld++,bst[p.second].lz+=pp[i].first;
    root=join2(p.first,p.second);
    //cout<<"--> ";trv(root);cout<<endl;
  }
  dfs(root);
  for(int i=1;i<=k;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}