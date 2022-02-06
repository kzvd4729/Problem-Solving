/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/30/2019 13:11                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 6700 KB                              
*  problem: https://codeforces.com/gym/102001/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
int aa[N+2],qm[N+2],zr[N+2];
 int seg[5*N+2],lazy[5*N+2];
void tooLazy(int node,int lo,int hi)
{
  seg[node]+=lazy[node];
  if(lo!=hi)lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
  lazy[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  tooLazy(node,lo,hi);if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=vl;tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);upd(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
void upd(int node,int lo,int hi,int id,int vl)
{
  tooLazy(node,lo,hi);if(lo==hi){seg[node]=vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]); 
}
 int lt[N+2],rt[N+2],con[N+2],sm[N+2];
void no(){cout<<"Impossible"<<endl,exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i],qm[i]=qm[i-1]+aa[i],zr[i]=zr[i-1]+(aa[i]==0);
   vector<pair<int,int> >v;
  for(int i=1;i<=m;i++)
  {
    int x,y;cin>>x>>y>>sm[i];lt[i]=x,rt[i]=y;
    v.push_back({x,-i});v.push_back({y,i});
  }
  sort(v.begin(),v.end());
  for(int i=0;i<5*N+2;i++)seg[i]=inf;
   int cnt=0,pt=0;
  for(int i=1;i<=n;i++)
  {
    while(pt<v.size())
    {
      if(v[pt].first<=i&&v[pt].second<0)
      {
        int id=-v[pt].second;
        ++cnt;int mx=qm[rt[id]]-qm[lt[id]-1]+zr[rt[id]]-zr[lt[id]-1];
        if(sm[id]>mx)no();mx-=sm[id];
        //cout<<cnt<<" --> "<<mx<<endl;
        upd(1,1,N,cnt,mx);con[id]=cnt;
        pt++;
      }
      else break;
    }
    if(aa[i]==0)
    {
      if(seg[1]<=1)aa[i]=1;
      else 
      {
        aa[i]=-1;upd(1,1,N,1,cnt,-2);
      }
    }
    while(pt<v.size())
    {
      if(v[pt].first<=i)
      {
        int id=v[pt].second;
        upd(1,1,N,con[id],inf);//con[id]=cnt;
        pt++;
      }
      else break;
    }
  }
  for(int i=1;i<=n;i++)qm[i]=qm[i-1]+aa[i];
  for(int i=1;i<=m;i++)
  {
    if(qm[rt[i]]-qm[lt[i]-1]<sm[i])no();
  }
  for(int i=1;i<=n;i++)cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}