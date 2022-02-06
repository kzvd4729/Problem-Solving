/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2019 19:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/27/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int f=0;
  for(int i=2;i<=n;i++)
    if(aa[i]<aa[i-1])f=1;
  if(!f)cout<<0<<endl,exit(0);
  f=0;
  for(int i=2;i<=n;i++)
    if(aa[i]>aa[i-1])f=1;
  if(!f)cout<<0<<endl,exit(0);
   cout<<3<<endl;
  pair<int,int>fr[N+2],bc[N+2];
  fr[1]={aa[1],1};
  for(int i=2;i<=n;i++)
  {
    if(aa[i]<fr[i-1].first)
      fr[i]={aa[i],i};
    else fr[i]=fr[i-1];
  }
  bc[n]={aa[n],n};
  for(int i=n-1;i>=1;i--)
  {
    if(aa[i]<bc[i+1].first)
      bc[i]={aa[i],i};
    else bc[i]=bc[i+1];
  }
  for(int i=2;i<n;i++)
  {
    if(fr[i-1].first<aa[i]&&bc[i+1].first<aa[i])
      cout<<fr[i-1].second<<" "<<i<<" "<<bc[i+1].second<<endl,exit(0);
  }
  fr[1]={aa[1],1};
  for(int i=2;i<=n;i++)
  {
    if(aa[i]>fr[i-1].first)
      fr[i]={aa[i],i};
    else fr[i]=fr[i-1];
  }
  bc[n]={aa[n],n};
  for(int i=n-1;i>=1;i--)
  {
    if(aa[i]>bc[i+1].first)
      bc[i]={aa[i],i};
    else bc[i]=bc[i+1];
  }
  for(int i=2;i<n;i++)
  {
    if(fr[i-1].first>aa[i]&&bc[i+1].first>aa[i])
      cout<<fr[i-1].second<<" "<<i<<" "<<bc[i+1].second<<endl,exit(0);
  }
  return 0;
}