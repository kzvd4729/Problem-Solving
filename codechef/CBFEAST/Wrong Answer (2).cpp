/****************************************************************************************
*  @author: kzvd4729                                         created: 15-12-2018 14:23:09                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/DEC18A/problems/CBFEAST
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e5;
struct segment
{
  int all,mx,lt,rt,dmn,dmx;
}seg[5*N+2],inv;
void upd(int node,int lo,int hi,int id,int vl1,int vl2)
{
  if(lo==hi)
  {
    seg[node]={vl1,vl1,vl1,vl1,vl2,vl2};return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl1,vl2);
  else upd(node*2+1,md+1,hi,id,vl1,vl2);
  segment p1=seg[node*2],p2=seg[node*2+1],p;
  p.all=p1.all+p2.all;
  p.lt=max(p1.lt,p1.all+p2.lt);p.lt=max(p.lt,p.all);
  p.rt=max(p2.rt,p2.all+p1.rt);p.rt=max(p.rt,p.all);
  p.mx=max(max(p1.mx,p2.mx),max(p.lt,p.rt));
  p.dmn=min(p1.dmn,p2.dmn);p.dmx=max(p1.dmx,p2.dmx);
  seg[node]=p;
}
segment qry(int node,int lo,int hi,int l,int r,int dl,int dr)
{
  if(lo>r||hi<l)return inv;if(l>r)return inv;
  if(seg[node].dmn>dr||seg[node].dmx<dl)return inv;
  if(seg[node].dmn>=dl&&seg[node].dmx<=dr)return seg[node];
  int md=(lo+hi)/2;
  segment p1=qry(node*2,lo,md,l,r,dl,dr);
  segment p2=qry(node*2+1,md+1,hi,l,r,dl,dr);
  segment p;
  p.all=p1.all+p2.all;
  p.lt=max(p1.lt,p1.all+p2.lt);p.lt=max(p.lt,p.all);
  p.rt=max(p2.rt,p2.all+p1.rt);p.rt=max(p.rt,p.all);
  p.mx=max(max(p1.mx,p2.mx),max(p.lt,p.rt));
  p.dmn=min(p1.dmn,p2.dmn);p.dmx=max(p1.dmx,p2.dmx);
  return p;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q,k;cin>>q>>k;
  int idl=2e5+1,idr=2e5;int last=0;
  while(q--)
  {
    int ty,c;cin>>ty>>c;c^=last;
    if(ty==1)
    {
      idl--;int d;cin>>d;
      upd(1,1,N,idl,d,c);
    }
    else if(ty==2)
    {
      idr++;int d;cin>>d;
      upd(1,1,N,idr,d,c);
    }
    else
    {
      last=qry(1,1,N,idl,idr,c-k,c+k).mx;
      if(last<0)last=0;
      cout<<last<<"\n";
    }
  }
  return 0;
}