/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-12-15 19:05:35                      
*  solution_verdict: RE                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2007 ms                                         memory_used: 305792 KB                            
*  problem: https://atcoder.jp/contests/agc029/tasks/agc029_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,R=1e9;
int aa[N+2],nw=1;
struct segment
{
  int l,r,vl;
}seg[130*N+2];
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].vl=vl;return ;
  }
  int md=(lo+hi)/2;
  if(!seg[node].l)seg[node].l=++nw;
  if(!seg[node].r)seg[node].r=++nw;
  if(seg[node].vl)
  {
    seg[seg[node].l].vl=seg[node].vl;
    seg[seg[node].r].vl=seg[node].vl;
    seg[node].vl=0;
  }
  upd(seg[node].l,lo,md,lt,rt,vl);
  upd(seg[node].r,md+1,hi,lt,rt,vl);
}
int qry(int node,int lo,int hi,int id)
{
  if(lo==hi)return seg[node].vl;
  int md=(lo+hi)/2;
  if(!seg[node].l)seg[node].l=++nw;
  if(!seg[node].r)seg[node].r=++nw;
  if(seg[node].vl)
  {
    seg[seg[node].l].vl=seg[node].vl;
    seg[seg[node].r].vl=seg[node].vl;
    seg[node].vl=0;
  }
  if(id<=md)return qry(seg[node].l,lo,md,id);
  else return qry(seg[node].r,md+1,hi,id);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
   int sz=1;upd(1,1,R,1,aa[1],1);
  for(int i=2;i<=n;i++)
  {
    if(aa[i]>aa[i-1])
      upd(1,1,R,aa[i-1]+1,aa[i],1);
    else
    {
      int f=0;
      for(int j=aa[i];j>=1;j--)
      {
        int xx=qry(1,1,R,j);
        if(xx<sz)
        {
          upd(1,1,R,j,j,xx+1);
          if(j<aa[i])upd(1,1,R,j+1,aa[i],1);
          f=1;break;
        }
      }
      if(f==0)
      {
        upd(1,1,R,aa[i],aa[i],++sz);
        //if(aa[i]>1)upd(1,1,R,2,aa[i],1);
      }
    }
  }
  cout<<sz<<endl;
  return 0;
}