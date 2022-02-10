/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-26 21:38:16                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1188
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t,tc,x,last[N+2],root[N+2],tmp,sz,n,q,lt,rt;
struct segment
{
  int l,r,sum;
}seg[40*N];
void upd(int node,int lo,int hi,int pnode,int id,int vl)
{
  if(lo==hi)
  {
    seg[node].sum=seg[pnode].sum+vl;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++sz;
    upd(seg[node].l,lo,md,seg[pnode].l,id,vl);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++sz;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id,vl);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sum;
  int md=(lo+hi)/2;
  return query(seg[node].l,lo,md,lt,rt)+query(seg[node].r,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    memset(seg,0,sizeof(seg));
    memset(last,0,sizeof(last));

    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      if(last[x])
      {
        tmp=++sz;
        upd(tmp,1,N,root[i-1],last[x],-1);
        root[i]=++sz;
        upd(root[i],1,N,tmp,i,1);
      }
      else
      {
        root[i]=++sz;
        upd(root[i],1,N,root[i-1],i,1);
      }
      last[x]=i;
    }
    cout<<"Case "<<++tc<<":"<<endl;
    while(q--)
    {
      cin>>lt>>rt;
      cout<<query(root[rt],1,N,lt,rt)<<endl;
    }

  }
  return 0;
}