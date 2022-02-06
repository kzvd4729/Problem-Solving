/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/04/2020 20:36                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 670 ms                                          memory_used: 54000 KB                             
*  problem: https://codeforces.com/contest/484/problem/E
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
const int N=1e5;
 struct segment
{
  int l,r,ls,rs,sm,al;
}seg[N*20+2];
void merge(segment &c,segment &a,segment &b)
{
  c.ls=a.ls;if(a.al)c.ls+=b.ls;
  c.rs=b.rs;if(b.al)c.rs+=a.rs;
  c.sm=max({a.sm,b.sm,c.ls,c.rs,a.rs+b.ls});
  c.al=(a.al&b.al);
}
int rot[N+2],nw;
void upd(int nd,int pnd,int lo,int hi,int id)
{
  if(lo==hi)
  {
    seg[nd].sm=1;seg[nd].ls=1;seg[nd].rs=1;seg[nd].al=1;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[nd].l)seg[nd].l=++nw;upd(seg[nd].l,seg[pnd].l,lo,md,id);
    seg[nd].r=seg[pnd].r;
  }
  else
  {
    if(!seg[nd].r)seg[nd].r=++nw;upd(seg[nd].r,seg[pnd].r,md+1,hi,id);
    seg[nd].l=seg[pnd].l;
  }
  merge(seg[nd],seg[seg[nd].l],seg[seg[nd].r]);
}
segment get(int nd,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return seg[0];
  if(lo>=lt&&hi<=rt)return seg[nd];
  int md=(lo+hi)/2;
   segment a=get(seg[nd].l,lo,md,lt,rt);
  segment b=get(seg[nd].r,md+1,hi,lt,rt);
   segment c;merge(c,a,b);return c;
}
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seg[0].al=1;
  int n;cin>>n;vector<int>v;map<int,vector<int> >mp;
  for(int i=1;i<=n;i++)cin>>a[i],v.push_back(a[i]),mp[a[i]].push_back(i);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  reverse(v.begin(),v.end());
   int ls=0;
  for(int i=0;i<v.size();i++)
  {
    for(auto x:mp[v[i]])
    {
      rot[i]=++nw;upd(rot[i],ls,1,n,x);
      ls=rot[i];
    }
  }
  //for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
  int q;cin>>q;
  while(q--)
  {
    int l,r,w;cin>>l>>r>>w;
    int lo=0,hi=v.size(),md;
    while(lo<hi)
    {
      md=(lo+hi)/2;
      segment s=get(rot[md],1,n,l,r);
      if(s.sm>=w)hi=md;else lo=md+1;
    }
    cout<<v[lo]<<'\n';
  }
   return 0;
}