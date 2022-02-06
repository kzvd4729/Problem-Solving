/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2018 18:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 17200 KB                             
*  problem: https://codeforces.com/contest/482/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,bit[32][N+2],aa[N+2],seg[5*N+2];
struct data
{
  int lt,rt,xx;
};
vector<data>qr;
void upd(int id,int x,int vl)
{
  for( ;x<=n;x+=x&-x)
    bit[id][x]+=vl;
}
int qry(int id,int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret+=bit[id][x];
  return ret;
}
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]=aa[lo];return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=seg[node*2]&seg[node*2+1];
}
int qry(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return (1<<30)-1;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return qry(node*2,lo,md,lt,rt)&qry(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int q;cin>>n>>q;
  while(q--)
  {
    int lt,rt,xx;cin>>lt>>rt>>xx;
    qr.push_back({lt,rt,xx});
    for(int i=0;i<30;i++)
    {
      if((xx&(1<<i)))
      {
        upd(i,lt,1);upd(i,rt+1,-1);
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<30;j++)
    {
      if(qry(j,i))aa[i]|=(1<<j);
    }
  }
  build(1,1,n);
  for(auto x:qr)
  {
    if(qry(1,1,n,x.lt,x.rt)!=x.xx)
      cout<<"NO"<<endl,exit(0);
  }
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}