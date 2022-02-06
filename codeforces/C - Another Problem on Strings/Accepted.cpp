/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2018 17:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 278 ms                                          memory_used: 6000 KB                              
*  problem: https://codeforces.com/contest/165/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int k;cin>>k;
  string s;cin>>s;int n=s.size();
  for(int i=1;i<=n;i++)
  {
    qm[i]=qm[i-1]+s[i-1]-'0';
  }
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    int lo,md,hi,p1=-1,p2=-1;
    lo=i,hi=n;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      int one=qm[md]-qm[i-1];
      if(one>=k)hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      if(qm[md]-qm[i-1]==k)
      {
        p1=md;break;
      }
    }
     lo=i,hi=n;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      int one=qm[md]-qm[i-1];
      if(one>k)hi=md;
      else lo=md;
    }
    for(md=hi;md>=lo;md--)
    {
      if(qm[md]-qm[i-1]==k)
      {
        p2=md;break;
      }
    }
     if(p1>0&&p2>0)
      ans+=(p2-p1+1)*1LL;
  }
  cout<<ans<<endl;
  return 0;
}