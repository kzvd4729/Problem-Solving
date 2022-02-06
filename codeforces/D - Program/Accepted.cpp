/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/14/2021 21:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 13800 KB                             
*  problem: https://codeforces.com/contest/1473/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,inf=1e9;
int mn[4*N+8],lz[4*N+8],mx[4*N+8];
void tooLazy(int nd,int lo,int hi)
{
  mn[nd]+=lz[nd];mx[nd]+=lz[nd];
  if(lo!=hi)lz[nd*2]+=lz[nd],lz[nd*2+1]+=lz[nd];
  lz[nd]=0;
}
void build(int nd,int lo,int hi)
{
  mn[nd]=0,mx[nd]=0,lz[nd]=0;
  if(lo==hi)return ;
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
}
void upd(int nd,int lo,int hi,int lt,int rt,int ad)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[nd]+=ad;tooLazy(nd,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  upd(nd*2,lo,md,lt,rt,ad);upd(nd*2+1,md+1,hi,lt,rt,ad);
  mn[nd]=min(mn[nd*2],mn[nd*2+1]);
  mx[nd]=max(mx[nd*2],mx[nd*2+1]);
}
int getMin(int nd,int lo,int hi,int lt,int rt)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return inf;
  if(lo>=lt&&hi<=rt)return mn[nd];
  int md=(lo+hi)/2;
  return min(getMin(nd*2,lo,md,lt,rt),getMin(nd*2+1,md+1,hi,lt,rt));
}
int getMax(int nd,int lo,int hi,int lt,int rt)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return -inf;
  if(lo>=lt&&hi<=rt)return mx[nd];
  int md=(lo+hi)/2;
  return max(getMax(nd*2,lo,md,lt,rt),getMax(nd*2+1,md+1,hi,lt,rt));
}
int a[N+2],b[N+2],mnx[N+2],mxx[N+2],x[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,q;cin>>n>>q;string s;cin>>s;
    //memset(mn,0,sizeof mn);
    //memset(mx,0,sizeof mx);
    //memset(lz,0,sizeof lz);
    build(1,1,n);
    for(int i=n;i>=1;i--)
    {
      if(s[i-1]=='+')upd(1,1,n,i,n,1);
      else upd(1,1,n,i,n,-1);
       a[i]=getMax(1,1,n,i,n);
      b[i]=getMin(1,1,n,i,n);
    }
    a[n+1]=0,b[n+1]=0;
    int bl=0;
    for(int i=1;i<=n;i++)
    {
      if(s[i-1]=='+')bl++;
      else bl--;
       mxx[i]=max(mxx[i-1],bl);
      mnx[i]=min(mnx[i-1],bl);
      x[i]=bl;
    }
    while(q--)
    {
      int l,r;cin>>l>>r;
      int lo=mnx[l-1],hi=mxx[l-1];
       lo=min(lo,x[l-1]+b[r+1]);
      hi=max(hi,x[l-1]+a[r+1]);
      //cout<<l<<" "<<r<<" "<<hi-lo+1<<endl;
      cout<<hi-lo+1<<" ";
    }
  }
  return 0;
}