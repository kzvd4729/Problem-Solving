/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/20/2018 00:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 52300 KB                             
*  problem: https://codeforces.com/contest/381/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,q,u,v;
string s;
struct segment
{
  int lt,rt,hr;
}seg[4000006];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    if(s[lo-1]=='(')
    {
      seg[node].lt=1;
      seg[node].hr=0;
      seg[node].rt=0;
    }
    else
    {
      seg[node].lt=0;
      seg[node].hr=0;
      seg[node].rt=1;
    }
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
   seg[node].lt=seg[node*2].lt+seg[node*2+1].lt;
  seg[node].rt=seg[node*2].rt+seg[node*2+1].rt;
  seg[node].hr=seg[node*2].hr+seg[node*2+1].hr+min(seg[node*2].lt-seg[node*2].hr,seg[node*2+1].rt-seg[node*2+1].hr);
 }
segment query(int node,int lo,int hi,int lft,int rgt)
{
  if(lo>rgt||hi<lft)return {0,0,0};
  if(lo>=lft&&hi<=rgt)return seg[node];
  int md=(lo+hi)/2;
  segment p1=query(node*2,lo,md,lft,rgt);
  segment p2=query(node*2+1,md+1,hi,lft,rgt);
  return {p1.lt+p2.lt,p1.rt+p2.rt,p1.hr+p2.hr+min(p1.lt-p1.hr,p2.rt-p2.hr)};
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>s;
  n=s.size();
  build(1,1,n);
  cin>>q;
  while(q--)
  {
    cin>>u>>v;
    segment p=query(1,1,n,u,v);
    cout<<2*p.hr<<endl;
  }
  return 0;
}