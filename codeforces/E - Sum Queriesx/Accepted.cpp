/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/05/2019 22:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1528 ms                                         memory_used: 57200 KB                             
*  problem: https://codeforces.com/contest/1217/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
const int inf=2e9+2;
int aa[N+2];
 pair<int,int>seg[9][4*N+2];
void upd(int i,int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[i][node]={vl,inf};return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(i,node*2,lo,md,id,vl);
  else upd(i,node*2+1,md+1,hi,id,vl);
   if(seg[i][node*2].first<seg[i][node*2+1].first)
  {
    seg[i][node].first=seg[i][node*2].first;
    seg[i][node].second=min(seg[i][node*2].second,seg[i][node*2+1].first);
  }
  else
  {
    seg[i][node].first=seg[i][node*2+1].first;
    seg[i][node].second=min(seg[i][node*2].first,seg[i][node*2+1].second);
  }
}
pair<int,int>get(int i,int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {inf,inf};
  if(lo>=lt&&hi<=rt)return seg[i][node];
  int md=(lo+hi)/2;
  pair<int,int>p1=get(i,node*2,lo,md,lt,rt);
  pair<int,int>p2=get(i,node*2+1,md+1,hi,lt,rt);
   pair<int,int>p;
  if(p1.first<p2.first)
  {
    p.first=p1.first;
    p.second=min(p1.second,p2.first);
  }
  else
  {
    p.first=p2.first;
    p.second=min(p1.first,p2.second);
  }
  return p;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;int id=0,xx=x;
    for(int c=0;c<=8;c++)
    {
      int r=x%10;x/=10;
      if(r)upd(id,1,1,n,i,xx);
      else upd(id,1,1,n,i,inf);
      id++;
    }
  }
  while(q--)
  {
    int ty,l,r;cin>>ty>>l>>r;
    if(ty==1)
    {
      int x=r,id=0;
      for(int c=0;c<=8;c++)
      {
        int rm=x%10;x/=10;
        if(rm)upd(id,1,1,n,l,r);
        else upd(id,1,1,n,l,inf);
        id++;
      }
    }
    else
    {
      int ans=inf;
      for(int i=0;i<=8;i++)
      {
        pair<int,int>p=get(i,1,1,n,l,r);
        if(p.first<inf&&p.second<inf)
          ans=min(ans,p.first+p.second);
      }
      if(ans==inf)cout<<-1<<"\n";
      else cout<<ans<<"\n";
    }
  }
  return 0;
}