/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/03/2020 21:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/gym/102465/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int mn[N+2],mx[N+2];
pair<int,int>pp[N+2];
bool ck(int n,int sz)
{
 int m=inf,id=-1;
 for(int i=1;i<=n;i++)if(mn[i]<m)m=mn[i],id=i;
  int l=id,r=id;
 for(int i=mn[id];i<=n;i++)
 {
  while(r<n&&mn[r+1]<=i)r++;while(l>1&&mn[l-1]<=i)l--;
    int nx=i+sz-1;if(nx>n)return false;
   l=max(l,pp[nx].first);r=min(r,pp[nx].second);
  if(r-l+1>=sz)return true;
 }
 return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>mn[i]>>mx[i],mn[i]++,mx[i]++;
   int m=0,id=-1;
 for(int i=1;i<=n;i++)if(mx[i]>m)m=mx[i],id=i;
  int l=id,r=id;
 for(int i=mx[id];i>=1;i--)
 {
  while(r<n&&mx[r+1]>=i)r++;while(l>1&&mx[l-1]>=i)l--;
  pp[i]={l,r};
 }
  int lo=1,hi=n,md;
 while(hi-lo>2)
 {
  md=(lo+hi)/2;
  if(ck(n,md))lo=md;else hi=md;
 }
 for(md=hi;md>=lo;md--)
  if(ck(n,md))cout<<md<<endl,exit(0);
  return 0;
}