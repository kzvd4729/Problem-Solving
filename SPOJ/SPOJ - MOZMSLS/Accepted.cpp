/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-29 21:56:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 50                                         memory_used (MB): 35.8                            
*  problem: https://vjudge.net/problem/SPOJ-MOZMSLS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long t,n,q,l,r;
string s;

struct segment
{
  long s,m,ms,sm,sms;
}seg[5*N];
void build(long node,long lo,long hi)
{
  if(lo==hi)
  {
    if(s[lo-1]=='s')seg[node].s++;
    if(s[lo-1]=='m')seg[node].m++;
    return ;
  }
  long md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);

  seg[node].s=seg[node*2].s+seg[node*2+1].s;
  seg[node].m=seg[node*2].m+seg[node*2+1].m;

  seg[node].ms=seg[node*2].ms+seg[node*2+1].ms+seg[node*2].m*seg[node*2+1].s;
  seg[node].sm=seg[node*2].sm+seg[node*2+1].sm+seg[node*2].s*seg[node*2+1].m;

  seg[node].sms=seg[node*2].sms+seg[node*2+1].sms+seg[node*2].s*seg[node*2+1].ms+seg[node*2].sm*seg[node*2+1].s;

}

segment query(long node,long lo,long hi,long lt,long rt)
{
  if(lo>rt||hi<lt)return {0LL,0LL,0LL,0LL,0LL};
  if(lo>=lt&&hi<=rt)return seg[node];
  long md=(lo+hi)/2;
  segment p1=query(node*2,lo,md,lt,rt);
  segment p2=query(node*2+1,md+1,hi,lt,rt);

  segment p;

  p.s=p1.s+p2.s;
  p.m=p1.m+p2.m;

  p.ms=p1.ms+p2.ms+p1.m*p2.s;
  p.sm=p1.sm+p2.sm+p1.s*p2.m;
  p.sms=p1.sms+p2.sms+p1.s*p2.ms+p1.sm*p2.s;

  return p;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>s)
  {
    for(long i=0;i<5*N;i++)
    {
      seg[i].s=0;
      seg[i].m=0;
      seg[i].ms=0;
      seg[i].sm=0;
      seg[i].sms=0;
    }
    n=s.size();
    build(1,1,n);
    cin>>q;
    while(q--)
    {
      cin>>l>>r;
      segment pp=query(1,1,n,l,r);
      cout<<pp.sms<<endl;
    }
  }
  return 0;
}