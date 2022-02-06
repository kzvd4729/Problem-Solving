/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2018 00:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 39200 KB                             
*  problem: https://codeforces.com/contest/1075/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long inf=1e14;
long aa[N+2],rgt[N+2],idd[N+2],ty[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,m;cin>>n>>m;
  for(long i=1;i<=n+m;i++)
    cin>>aa[i];
  for(long i=1;i<=n+m;i++)
    cin>>ty[i];
  long last=inf,id=0;
  for(long i=n+m;i>=1;i--)
  {
    if(!ty[i])
    {
      rgt[i]=last-aa[i];
      idd[i]=id;
    }
    else
    {
      last=aa[i];id=i;
    }
  }
  last=-inf;
  for(long i=1;i<=n+m;i++)
  {
    if(!ty[i])
    {
      long ds=aa[i]-last;
      if(ds<=rgt[i])cnt[id]++;
      else cnt[idd[i]]++;
    }
    else
    {
      last=aa[i];id=i;
    }
  }
  for(long i=1;i<=n+m;i++)
  {
    if(ty[i])cout<<cnt[i]<<" ";
  }
  cout<<endl;
  return 0;
}