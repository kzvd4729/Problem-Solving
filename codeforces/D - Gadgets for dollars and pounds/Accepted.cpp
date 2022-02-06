/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2019 19:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 764 ms                                          memory_used: 39100 KB                             
*  problem: https://codeforces.com/contest/609/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int dl[N+2],pn[N+2],k,n1,n2,s,id1,id2,pr;
struct data
{
  int id;long cs;
}aa[N+2],bb[N+2];
bool cmp(data A,data B)
{
  return A.cs<B.cs;
}
bool ok(int id)
{
  int mn1=1e9,mn2=1e9;
  for(int i=1;i<=id;i++)
  {
    if(dl[i]<mn1)mn1=dl[i],id1=i;
  }
  for(int i=1;i<=id;i++)
  {
    if(pn[i]<mn2)mn2=pn[i],id2=i;
  }
  long now=1e18;
  for(int i=0;i<=k;i++)
  {
    int j=k-i;if(i>n1||j>n2)continue;
    long tt=aa[i].cs*mn1+bb[j].cs*mn2;
    if(tt<now)now=tt,pr=i;
  }
  return now<=s;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m>>k>>s;
  for(int i=1;i<=n;i++)cin>>dl[i];
  for(int i=1;i<=n;i++)cin>>pn[i];
  for(int i=1;i<=m;i++)
  {
    int ty,cs;cin>>ty>>cs;
    if(ty==1)aa[++n1]={i,cs};
    else bb[++n2]={i,cs};
  }
  sort(aa+1,aa+n1+1,cmp);sort(bb+1,bb+n2+1,cmp);
  for(int i=1;i<=n1;i++)aa[i].cs+=aa[i-1].cs;
  for(int i=1;i<=n2;i++)bb[i].cs+=bb[i-1].cs;
  int lo=1,hi=n,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ok(md))hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(ok(md))break;
  if(md>n)cout<<-1<<endl,exit(0);
  cout<<md<<endl;
   for(int i=1;i<=pr;i++)
    cout<<aa[i].id<<" "<<id1<<endl;
  for(int i=1;i<=k-pr;i++)
    cout<<bb[i].id<<" "<<id2<<endl;
   return 0;
}