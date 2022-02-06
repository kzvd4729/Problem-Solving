/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/31/2019 19:55                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 54000 KB                             
*  problem: https://codeforces.com/contest/853/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],sz,root[N+2],prnt[N+2];
struct persistent
{
  int l,r,sm;
}seg[22*N+2];
void upd(int node,int pnode,int lo,int hi,int id)
{
  if(lo==hi){seg[node].sm=seg[pnode].sm+1;return ;}
  int md=(lo+hi)/2;
  if(id<=md)
  {
    seg[node].l=++sz;seg[node].r=seg[pnode].r;
    upd(seg[node].l,seg[pnode].l,lo,md,id);
  }
  else
  {
    seg[node].r=++sz;seg[node].l=seg[pnode].l;
    upd(seg[node].r,seg[pnode].r,md+1,hi,id);
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int get(int node,int pnode,int lo,int hi,int lt,int rt)
{
  if(lt>rt)return 0;
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sm-seg[pnode].sm;
  int md=(lo+hi)/2;
  int p1=get(seg[node].l,seg[pnode].l,lo,md,lt,rt);
  int p2=get(seg[node].r,seg[pnode].r,md+1,hi,lt,rt);
  return p1+p2;
}
template<typename T>//container
void P(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>aa[i];
   vector<vector<int> >qr(q);
  for(int i=0;i<q;i++)
  {
    int a,b,c,d;qr[i].resize(5);
    for(int j=0;j<4;j++)
      cin>>qr[i][j];
    qr[i][4]=i;
  }
  sort(qr.begin(),qr.end(),[](vector<int>a,vector<int>b)
    {return a[2]<b[2];});
   /*for(auto x:qr)
    P(x);*/
     int pt=1;
  for(auto x:qr)
  {
    while(pt<=x[2])
    {
      root[pt]=++sz;
      upd(root[pt],root[pt-1],1,n,aa[pt]);
      pt++;
    }
    long ans=1LL*n*(n-1)/2;
    ans-=1LL*(n-x[2])*(n-x[2]-1)/2;
    ans-=1LL*(x[0]-1)*(x[0]-2)/2;
     int p1=get(root[x[2]],root[x[0]-1],1,n,x[3]+1,n);
    int p2=get(root[x[2]],root[x[0]-1],1,n,1,x[1]-1);
    ans-=1LL*p1*(p1-1)/2-1LL*p2*(p2-1)/2;
     prnt[x[4]]=ans;
  }
  for(int i=0;i<q;i++)
    cout<<prnt[i]<<" ";
  cout<<endl;
  return 0;
}