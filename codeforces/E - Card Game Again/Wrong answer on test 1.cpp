/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/14/2018 22:54                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 9400 KB                              
*  problem: https://codeforces.com/contest/818/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,k,cnt[12];
long qm[N+2][12];
vector<long>fc;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
   for(long i=2,sq=sqrt(k+1);i<=sq;i++)
  {
    if(k%i==0)
    {
      fc.push_back(i);
      while(k%i==0)
      {
        k/=i;
        cnt[fc.size()-1]++;
      }
    }
  }
  if(k!=1)
  {
    fc.push_back(k);
    cnt[fc.size()-1]++;
  }
  cout<<fc.size()<<endl;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;
    for(long j=0;j<fc.size();j++)qm[i][j]=qm[i-1][j];
    for(long j=0;j<fc.size();j++)
    {
      while(x%fc[j]==0)
      {
        qm[i][j]++;
        x/=fc[j];
      }
    }
  }
  long ans=0;
  for(long i=1;i<=n;i++)
  {
    long lo=i,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      long f=0;
      for(long j=0;j<fc.size();j++)
      {
        if(qm[md][j]-qm[i-1][j]<cnt[j])
          f=1;
      }
      if(f==1)lo=md;
      else hi=md;
    }
    for(md=lo;md<=hi;md++)
    {
      long f=0;
      for(long j=0;j<fc.size();j++)
      {
        if(qm[md][j]-qm[i-1][j]<cnt[j])
          f=1;
      }
      if(f==0)break;
    }
    ans+=(n-md+1)*1LL;
  }
  cout<<ans<<endl;
  return 0;
}