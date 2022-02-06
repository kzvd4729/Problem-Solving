/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/07/2018 21:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 7100 KB                              
*  problem: https://codeforces.com/contest/1036/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e5;
long a[N+2],b[N+2],qm[N+2];
long s1,s2;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,m;cin>>n;
  for(long i=1;i<=n;i++)
    cin>>a[i],s1+=a[i];
  cin>>m;
  for(long i=1;i<=m;i++)
  {
    cin>>b[i],s2+=b[i];
    qm[i]=qm[i-1]+b[i];
  }
  if(s1!=s2)cout<<-1<<endl,exit(0);
  long sum=0,last=0,ans=0;
  for(long i=1;i<=n;i++)
  {
    sum+=a[i];
    long lo=last+1,hi=m,md;
    while(hi-lo>=3)
    {
      md=(lo+hi)/2;
      if(qm[md]-qm[last]>=sum)hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      if(qm[md]-qm[last]==sum)
      {
        ans++;last=md;
        sum=0;break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}