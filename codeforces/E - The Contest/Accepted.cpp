/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2019 22:43                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 140 ms                                          memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/1257/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int seg[5*N+2],lazy[5*N+2],n;
int aa[N+2],bb[N+2],cc[N+2],dd[N+2],cnt[N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    int tt=cc[n],rn=cc[n]-cc[lo];
    int cl=n-lo-rn+tt-rn;
    //if(lo==7)cout<<cl<<endl;
    seg[node]=cl+dd[lo];
    //cout<<"*"<<lo<<" "<<seg[node]<<endl;
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
void tooLazy(int node,int lo,int hi)
{
  seg[node]+=lazy[node];
  if(lo!=hi)
  {
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
  }
  lazy[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=vl;tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,c,x;cin>>a>>b>>c;n=a+b+c;
   for(int i=1;i<=a;i++)cin>>x,aa[x]=1,dd[x]=1;
  for(int i=1;i<=n;i++)dd[i]+=dd[i-1];
   for(int i=1;i<=b;i++)cin>>x,bb[x]=1;
  for(int i=1;i<=n;i++)bb[i]+=bb[i-1];
   for(int i=1;i<=c;i++)cin>>x,cc[x]=1;
  for(int i=1;i<=n;i++)cc[i]+=cc[i-1];
   build(1,0,n);int ans=seg[1];
   for(int i=1;i<=n;i++)
  {
    if(aa[i])
    {
      //cout<<"here"<<endl;
      upd(1,0,n,i,n,-1);
    }
    //cout<<seg[1]<<endl;
    ans=min(ans,seg[1]+bb[i]);
  }
  cout<<ans<<endl;
  return 0;
}