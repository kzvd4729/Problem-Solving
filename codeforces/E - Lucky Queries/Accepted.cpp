/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/14/2019 16:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1310 ms                                         memory_used: 99900 KB                             
*  problem: https://codeforces.com/contest/145/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s;
int lazy[5*N+2];
struct segment
{
  int f,s,fs,sf;
}seg[5*N+2];
void tooLazy(int node,int lo,int hi)
{
  if(!lazy[node])return ;
  swap(seg[node].f,seg[node].s);
  swap(seg[node].fs,seg[node].sf);
  if(lo!=hi)lazy[node*2]^=1,lazy[node*2+1]^=1;
  lazy[node]=0;
}
void mrge(segment &a,segment &b,segment &c)
{
  a.f=b.f+c.f,a.s=b.s+c.s;
  a.fs=max(b.f+c.fs,b.fs+c.s);
  a.sf=max(b.s+c.sf,b.sf+c.f);
}
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    if(s[lo-1]=='4')seg[node]={1,0,1,1};
    else seg[node]={0,1,1,1};
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  mrge(seg[node],seg[node*2],seg[node*2+1]);
}
void upd(int node,int lo,int hi,int lt,int rt)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]^=1;tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt);upd(node*2+1,md+1,hi,lt,rt);
  mrge(seg[node],seg[node*2],seg[node*2+1]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m>>s;
   build(1,1,n);
  while(m--)
  {
    cin>>s;
    if(s=="count")cout<<seg[1].fs<<"\n";
    else 
    {
      int l,r;cin>>l>>r;upd(1,1,n,l,r);
    }
  }
  return 0;
}