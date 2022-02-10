/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-16 00:25:38                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 20                                         memory_used (MB): 4.8                             
*  problem: https://vjudge.net/problem/SPOJ-GSS5
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e4,inf=2e9;
long aa[N+2];
struct segment
{
  long lt,rt,mx,sm;
}seg[5*N+2];
void mrge(segment &p,segment &p1,segment &p2)
{
  p.sm=p1.sm+p2.sm;
  p.lt=max(p1.lt,p1.sm+p2.lt);
  p.rt=max(p2.rt,p1.rt+p2.sm);
  p.mx=max(max(p1.mx,p2.mx),p1.rt+p2.lt);
}
void build(long node,long lo,long hi)
{
  if(lo==hi)
  {
    seg[node]={aa[lo],aa[lo],aa[lo],aa[lo]};return ;
  }
  long md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  mrge(seg[node],seg[node*2],seg[node*2+1]);
}
segment get(long node,long lo,long hi,long lt,long rt)
{
  if(lo>rt||hi<lt||lt>rt)return {-inf,-inf,-inf,0};
  if(lo>=lt&&hi<=rt)return seg[node];
  long md=(lo+hi)/2;segment p,p1,p2;
  p1=get(node*2,lo,md,lt,rt),p2=get(node*2+1,md+1,hi,lt,rt);
  mrge(p,p1,p2);return p;
}
long qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)qm[i]=qm[i-1]+aa[i];
    build(1,1,n);long q;cin>>q;
    while(q--)
    {
      int a,b,c,d;cin>>a>>b>>c>>d;
      long mx=-inf,sm=0;
      if(c>b)
      {
        segment p1=get(1,1,n,a,b);
        segment p2=get(1,1,n,c,d);
        //cout<<p1.rt<<" ** "<<p2.lt<<endl;
        cout<<qm[c-1]-qm[b]+p1.rt+p2.lt<<"\n";
      }
      else
      {
        segment p=get(1,1,n,c,b);mx=p.mx;
        segment p1=get(1,1,n,a,c-1);
        segment p2=get(1,1,n,b+1,d);
        mx=max(mx,qm[b]-qm[c-1]+max(p1.rt,0LL)+max(p2.lt,0LL));
        mx=max(mx,max(p1.rt,0LL)+p.lt);
        mx=max(mx,p.rt+max(p2.lt,0LL));
        cout<<mx<<"\n";
      }
    }
    cout<<endl;
  }
  return 0;
}