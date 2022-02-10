/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-24 15:00:00                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-CNTPRIME
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int t,tc,n,q,x,ty,seg[5*N],lazy[5*N];
bool prime(int x)
{
  for(int i=2;i<=sqrt(x);i++)
    if(x%i==0)return false;
  return true;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  int md=(lo+hi)/2;
  if(lazy[node]!=-1)
  {
    seg[node]=(hi-lo+1)*lazy[node];
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=-1;
  }
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node]=(hi-lo+1)*vl;
    if(lo!=hi)
    {
      lazy[node*2]=vl;
      lazy[node*2+1]=vl;
    }
    return ;
  }
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=seg[node*2]+seg[node*2+1];
}
int query(int node,int lo,int hi,int lt,int rt)
{
  int md=(lo+hi)/2;
  if(lazy[node]!=-1)
  {
    seg[node]=(hi-lo+1)*lazy[node];
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=-1;
  }
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int p1=query(node*2,lo,md,lt,rt);
  int p2=query(node*2+1,md+1,hi,lt,rt);
  return p1+p2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    for(int i=0;i<=4*N;i++)
    {
      seg[i]=0;
      lazy[i]=-1;
    }

    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      if(prime(x))
        upd(1,1,n,i,i,1);
      else upd(1,1,n,i,i,0);
    }
    printf("Case %d:\n",++tc);
    while(q--)
    {
      cin>>ty;
      int lt,rt,vl;
      if(ty==0)
      {
        cin>>lt>>rt>>vl;
        if(prime(vl))upd(1,1,n,lt,rt,1);
        else upd(1,1,n,lt,rt,0);
      }
      else
      {
        cin>>lt>>rt;
        cout<<query(1,1,n,lt,rt)<<endl;
      }
    }
  }
  return 0;
}