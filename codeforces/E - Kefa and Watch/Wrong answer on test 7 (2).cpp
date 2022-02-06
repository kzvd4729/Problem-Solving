/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2018 17:20                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 9000 KB                              
*  problem: https://codeforces.com/contest/580/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long mod=1e9+9,bs=29;
long pw[N+2],seg[5*N+2],lazy[5*N+2];
int n,m,k,aa[N+2];
string s;
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]=(aa[lo]*(pw[lo]-pw[lo-1]+mod)%mod)%mod;
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node]=(seg[node*2]+seg[node*2+1])%mod;
}
void too_lazy(int node,int lo,int hi)
{
  if(!lazy[node])return ;
  seg[node]=(lazy[node]*(pw[hi]-pw[lo-1]+mod)%mod)%mod;
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
    lazy[node]=vl;
    too_lazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=(seg[node*2]+seg[node*2+1])%mod;
}
long qry(int node,int lo,int hi,int lt,int rt)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  long p1=qry(node*2,lo,md,lt,rt);
  long p2=qry(node*2+1,md+1,hi,lt,rt);
  return (p1+p2)%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1LL;
  for(int i=1;i<=N;i++)
    pw[i]=(pw[i-1]*bs)%mod;
  for(int i=1;i<=N;i++)
    pw[i]=(pw[i-1]+pw[i])%mod;
   cin>>n>>m>>k>>s;
  for(int i=0;i<n;i++)aa[i+1]=s[i]-'0'+1;
  build(1,1,n);
  for(int i=1;i<=m+k;i++)
  {
    int ty,lt,rt,vl;cin>>ty>>lt>>rt>>vl;
    if(ty==1)
    {
      vl++;upd(1,1,n,lt,rt,vl);
    }
    else
    {
      if(vl==rt-lt+1)
      {
        cout<<"YES"<<endl;continue;
      }
      int lt1=lt,lt2=lt+vl;
      int df=min(vl,rt-lt2+1);
      long p1=qry(1,1,n,lt1,lt1+df-1);
      long p2=qry(1,1,n,lt2,lt2+df-1);
      p1=(p1*(pw[vl]-pw[vl-1]+mod)%mod)%mod;
      if(p1==p2)
      {
        cout<<"YES"<<endl;continue;
      }
      cout<<"NO"<<endl;
    }
  }
  return 0;
}