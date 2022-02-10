/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-29 11:47:51                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 530                                        memory_used (MB): 45.1                            
*  problem: https://vjudge.net/problem/SPOJ-MKTHNUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],nw,rt[N+2];
struct segment
{
  int l,r,sm;
}seg[N*20+2];
void upd(int node,int lo,int hi,int pnode,int id)
{
  if(lo==hi)
  {
    seg[node].sm=seg[pnode].sm+1;return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    seg[node].l=++nw;seg[node].r=seg[pnode].r;
    upd(seg[node].l,lo,md,seg[pnode].l,id);
  }
  else
  {
    seg[node].r=++nw;seg[node].l=seg[pnode].l;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id);
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int qry(int node,int pnode,int lo,int hi,int kth)
{
  if(lo==hi)return lo;
  int md=(lo+hi)/2;int xx=seg[seg[node].l].sm-seg[seg[pnode].l].sm;
  if(xx>=kth)return qry(seg[node].l,seg[pnode].l,lo,md,kth);
  else return qry(seg[node].r,seg[pnode].r,md+1,hi,kth-xx);
}
/*************** Data Compress **************/
int El[N+2],Cm[N+2];map<int,int>Mp;
void Compress(int n)
{
  sort(El+1,El+n+1);int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(Mp[El[i]])continue;
    Mp[El[i]]=++cnt;Cm[cnt]=El[i];
  }
}
////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];El[i]=aa[i];
  }
  Compress(n);for(int i=1;i<=n;i++)aa[i]=Mp[aa[i]];
  for(int i=1;i<=n;i++)
  {
    rt[i]=++nw;upd(rt[i],1,n,rt[i-1],aa[i]);
  }
  while(q--)
  {
    int l,r,k;cin>>l>>r>>k;
    cout<<Cm[qry(rt[r],rt[l-1],1,n,k)]<<"\n";
  }
  return 0;
}