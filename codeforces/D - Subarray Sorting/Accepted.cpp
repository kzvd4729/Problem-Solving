/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2019 15:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1013 ms                                         memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1187/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inv=1e9;
int aa[N+2],bb[N+2],seg[4*N+2];
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi){seg[node]=vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
int get(int node,int lo,int hi,int id)
{
  if(hi<=id)return seg[node];
  if(lo>id)return inv;
  int md=(lo+hi)/2;
  return min(get(node*2,lo,md,id),get(node*2+1,md+1,hi,id));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int bad=0;
    for(int i=1;i<=n;i++)cin>>aa[i],upd(1,1,n,i,aa[i]);
    for(int i=1;i<=n;i++)cin>>bb[i];
     for(int i=1;i<=n;i++)
    {
      int lo=1,hi=n,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(get(1,1,n,md)<=bb[i])hi=md;
        else lo=md;
      }
      int f=0;
      for(md=lo;md<=hi;md++)
      {
        if(get(1,1,n,md)==bb[i]){f=1;break;}
      }
      if(!f){bad=1;break;}
      upd(1,1,n,md,inv);
    }
    if(bad)cout<<"NO\n";
    else cout<<"YES\n";
  }
  return 0;
}