/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/16/2018 12:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2198 ms                                         memory_used: 6300 KB                              
*  problem: https://codeforces.com/contest/438/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e9+2;
int n,q,x;
struct segment
{
  int mod;
  long sum;
}seg[N*4+2];
void upd1(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node].sum=vl;
    seg[node].mod=vl+1;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd1(node*2,lo,md,id,vl);
  else upd1(node*2+1,md+1,hi,id,vl);
  seg[node].sum=seg[node*2].sum+seg[node*2+1].sum;
  seg[node].mod=max(seg[node*2].mod,seg[node*2+1].mod);
}
void upd2(int node,int lo,int hi,int lt,int rt,int mod)
{
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    if(seg[node].mod<mod)return ;
    if(lo==hi)
    {
      seg[node].sum=seg[node].sum%mod;
      seg[node].mod=seg[node].sum+1;
      return ;
    }
  }
  int md=(lo+hi)/2;
  upd2(node*2,lo,md,lt,rt,mod);
  upd2(node*2+1,md+1,hi,lt,rt,mod);
  seg[node].sum=seg[node*2].sum+seg[node*2+1].sum;
  seg[node].mod=max(seg[node*2].mod,seg[node*2+1].mod);
}
long query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sum;
  int md=(lo+hi)/2;
  long p1=query(node*2,lo,md,lt,rt);
  long p2=query(node*2+1,md+1,hi,lt,rt);
  return p1+p2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>q;
  for(int i=1;i<=n;i++)
    cin>>x,upd1(1,1,n,i,x);
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int lt,rt;cin>>lt>>rt;
      cout<<query(1,1,n,lt,rt)<<" ";
    }
    else if(ty==2)
    {
      int lt,rt,mod;cin>>lt>>rt>>mod;
      upd2(1,1,n,lt,rt,mod);
    }
    else
    {
      int id,vl;cin>>id>>vl;
      upd1(1,1,n,id,vl);
    }
  }
  cout<<endl;
  return 0;
}