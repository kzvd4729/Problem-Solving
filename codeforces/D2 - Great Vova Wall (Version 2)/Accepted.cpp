/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2018 23:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 16600 KB                             
*  problem: https://codeforces.com/contest/1092/problem/D2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],par[N+2],siz[N+2];
int seg[N*5+2],lazy[N*5+2];
void too_lazy(int node,int lo,int hi)
{
  if(!lazy[node])return ;
  seg[node]=lazy[node];
  if(lo!=hi)
  {
    lazy[node*2]=lazy[node];
    lazy[node*2+1]=lazy[node];
  }
  lazy[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]=vl;too_lazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
}
int qry(int node,int lo,int hi,int id)
{
  too_lazy(node,lo,hi);
  if(lo==hi)return seg[node];
  int md=(lo+hi)/2;
  if(id<=md)return qry(node*2,lo,md,id);
  else return qry(node*2+1,md+1,hi,id);
}
int _find(int x)
{
  if(x==par[x])return x;
  return par[x]=_find(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int mx=0;set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];st.insert({aa[i],i});
    mx=max(mx,aa[i]);
  }
  aa[n+1]=mx;aa[0]=mx;int cnt=0;
  for(int i=0;i<=n+1;i++)
    par[i]=i,siz[i]=1;
  for(int i=n;i>=0;i--)
  {
    if(aa[i]==aa[i+1])
    {
      int rt=_find(i+1);
      par[i]=rt;siz[rt]++;
    }
  }
  for(int i=0;i<=n+1;i++)upd(1,0,n+1,i,i,aa[i]);
  while(st.size())
  {
    pair<int,int>p=*st.begin();st.erase(p);
     int qq=qry(1,0,n+1,p.second);
    if(qq!=p.first)continue;
    if(p.first==mx)continue;
     int id=p.second;int rt=_find(id);
    if(siz[rt]%2)cout<<"NO"<<endl,exit(0);
     int lft=p.second-1,rgt=p.second+siz[rt];
    //cout<<lft<<" "<<rgt<<endl;
    int one=qry(1,0,n+1,lft),two=qry(1,0,n+1,rgt);
    if(one<=two)
    {
      int r1=_find(lft);par[r1]=rt;
      siz[rt]+=siz[r1];
      upd(1,0,n+1,lft+1,rgt-1,one);
    }
    if(one>=two)
    {
      int r1=_find(rgt);par[r1]=rt;
      siz[rt]+=siz[r1];
      upd(1,0,n+1,lft+1,rgt-1,two);
    }
  }
  cout<<"YES"<<endl;
  return 0;
}