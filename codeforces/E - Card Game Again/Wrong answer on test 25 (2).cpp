/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/14/2018 22:39                        
*  solution_verdict: Wrong answer on test 25                 language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 9400 KB                              
*  problem: https://codeforces.com/contest/818/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,k,cnt[12];
long qm[N+2][12];
vector<int>fc;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
   for(int i=2,sq=sqrt(n+1);i<=sq;i++)
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
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    for(int j=0;j<fc.size();j++)qm[i][j]=qm[i-1][j];
    for(int j=0;j<fc.size();j++)
    {
      while(x%fc[j]==0)
      {
        qm[i][j]++;
        x/=fc[j];
      }
    }
  }
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    int lo=i,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      int f=0;
      for(int j=0;j<fc.size();j++)
      {
        if(qm[md][j]-qm[i-1][j]<cnt[j])
          f=1;
      }
      if(f==1)lo=md;
      else hi=md;
    }
    for(md=lo;md<=hi;md++)
    {
      int f=0;
      for(int j=0;j<fc.size();j++)
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