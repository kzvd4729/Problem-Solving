/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-10 22:00:01                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 60                                         memory_used (MB): 23.6                            
*  problem: https://vjudge.net/problem/SPOJ-KGSS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,x,q;
struct segment
{
  int vl,idx;
}seg[1000006];
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node].vl=vl;
    seg[node].idx=id;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);

  if(seg[node*2].vl>seg[node*2+1].vl)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
segment query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {-1,-1};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  segment p1=query(node*2,lo,md,lt,rt);
  segment p2=query(node*2+1,md+1,hi,lt,rt);
  if(p1.vl>p2.vl)return p1;
  else return p2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    upd(1,1,n,i,x);
  }
  cin>>q;
  while(q--)
  {
    char ch;
    int lt,rt;
    cin>>ch>>lt>>rt;
    if(ch=='U')
      upd(1,1,n,lt,rt);
    else
    {
      int ans;
      segment tmp=query(1,1,n,lt,rt);
      ans=tmp.vl;
      int mm=ans;
      upd(1,1,n,tmp.idx,-1);
      ans+=query(1,1,n,lt,rt).vl;
      upd(1,1,n,tmp.idx,mm);
      cout<<ans<<endl;
    }
  }
  return 0;
}