/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2018 20:18:00                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 22.2M                                
*  problem: https://www.codechef.com/APRIL18A/problems/CUTPLANT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=1e5;
int seg[4*N],x,lazy[4*N],arr[N+2],t,n,print,brr[4*N],_seg[4*N];
vector<pair<int,int> >vc;
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]=arr[lo];
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lazy[node])
  {
    seg[node]=lazy[node];
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node]=vl;
    if(lo!=hi)
    {
      lazy[node*2]=vl;
      lazy[node*2+1]=vl;
    }
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lazy[node])
  {
    seg[node]=lazy[node];
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo>rt||hi<lt)return inf;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return min(query(node*2,lo,md,lt,rt),query(node*2+1,md+1,hi,lt,rt));
}
void _build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    _seg[node]=brr[lo];
    return ;
  }
  int md=(lo+hi)/2;
  _build(node*2,lo,md);
  _build(node*2+1,md+1,hi);
  _seg[node]=max(_seg[node*2],_seg[node*2+1]);
}
int _query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return -inf;
  if(lo>=lt&&hi<=rt)return _seg[node];
  int md=(lo+hi)/2;
  return max(_query(node*2,lo,md,lt,rt),_query(node*2+1,md+1,hi,lt,rt));
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    memset(seg,0,sizeof(seg));
    memset(_seg,0,sizeof(_seg));
    memset(lazy,0,sizeof(lazy));
    vc.clear();
    print=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
      cin>>brr[i];
      vc.push_back({brr[i],i});
    }
    int f=0;
    for(int i=1;i<=n;i++)if(brr[i]>arr[i])f=1;
    if(f==1)
    {
      cout<<-1<<endl;
      continue;
    }
    _build(1,1,n);
    sort(vc.begin(),vc.end());
    reverse(vc.begin(),vc.end());
//    int a,b;
//    while(cin>>a>>b)
//    {
//      cout<<_query(1,1,n,a,b)<<endl;
//    }
    for(auto x:vc)
    {
      int id=x.second;
      int vl=x.first;
      int lo,hi,md,lt,rt;
      if(query(1,1,n,id,id)==vl)continue;
      print++;
      lo=id;
      hi=n;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(query(1,1,n,id,md)<vl||_query(1,1,n,id,md)>vl)hi=md;
        else lo=md;
      }
      for(int i=hi;i>=lo;i--)
      {
        if(query(1,1,n,id,i)>=vl&&_query(1,1,n,id,i)<=vl)
        {
          rt=i;
          break;
        }
      }
      lo=1;
      hi=id;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(query(1,1,n,md,id)<vl||_query(1,1,n,md,id)>vl)lo=md;
        else hi=md;
      }
      for(int i=lo;i<=hi;i++)
      {
        if(query(1,1,n,i,id)>=vl&&_query(1,1,n,i,id)<=vl)
        {
          lt=i;
          break;
        }
      }
//      cout<<lt<<" "<<rt<<endl;
//      getchar();
      ///cout<<vl<<" "<<id<<" "<<query(1,1,n,id,id)<<" "<<lt<<" "<<rt<<endl;
      upd(1,1,n,lt,rt,vl);
    }
    cout<<print<<endl;
  }
  return 0;
}