/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-29 11:56:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 540                                        memory_used (MB): 46.1                            
*  problem: https://vjudge.net/problem/SPOJ-MKTHNUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2];

/********** Kth Number in a Range **************/
int Pr[N+2],Rt[N+2],R;
struct Persistent
{
  int l,r,sm;
}Seg[N*20+2];
void Add(int node,int lo,int hi,int pnode,int id)
{
  if(lo==hi)
  {
    Seg[node].sm=Seg[pnode].sm+1;return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    Seg[node].l=++R;Seg[node].r=Seg[pnode].r;
    Add(Seg[node].l,lo,md,Seg[pnode].l,id);
  }
  else
  {
    Seg[node].r=++R;Seg[node].l=Seg[pnode].l;
    Add(Seg[node].r,md+1,hi,Seg[pnode].r,id);
  }
  Seg[node].sm=Seg[Seg[node].l].sm+Seg[Seg[node].r].sm;
}
int Find(int node,int pnode,int lo,int hi,int kth)
{
  if(lo==hi)return lo;
  int md=(lo+hi)/2;int xx=Seg[Seg[node].l].sm-Seg[Seg[pnode].l].sm;
  if(xx>=kth)return Find(Seg[node].l,Seg[pnode].l,lo,md,kth);
  else return Find(Seg[node].r,Seg[pnode].r,md+1,hi,kth-xx);
}
void Build(int n)
{
  for(int i=1;i<=n;i++)
  {
    Rt[i]=++R;Add(Rt[i],1,n,Rt[i-1],Pr[i]);
  }
  //cout<<Find(Rt[i],Rt[i-1],1,n,k)<<endl;
}
///////////////////////////////////////////////////
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
  for(int i=1;i<=n;i++)Pr[i]=aa[i];Build(n);
  while(q--)
  {
    int l,r,k;cin>>l>>r>>k;
    cout<<Cm[Find(Rt[r],Rt[l-1],1,n,k)]<<"\n";
  }
  return 0;
}