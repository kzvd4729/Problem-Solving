/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2019 19:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/737/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,k,s,t,pr[N+2],cp[N+2],gs[N+2];
bool ok(int cc)
{
  int tm=0;
  for(int i=1;i<=k;i++)
  {
    int ds=gs[i]-gs[i-1];
    tm+=ds*2-min(ds,cc-ds);
  }
  return tm<=t;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k>>s>>t;
  for(int i=1;i<=n;i++)
    cin>>pr[i]>>cp[i];
  for(int i=1;i<=k;i++)
    cin>>gs[i];
  sort(gs+1,gs+k+1);
  int lo=0,hi=1e9,md;
  ++k;gs[k]=s;for(int i=1;i<=k;i++)lo=max(lo,gs[i]-gs[i-1]);
  while(hi-lo>1)
  {
    md=(lo+hi)/2;
    if(ok(md))hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(ok(md))break;
  int ans=2e9;
  for(int i=1;i<=n;i++)
  {
    if(cp[i]>=md)ans=min(ans,pr[i]);
  }
  if(ans>1e9)ans=-1;
  cout<<ans<<endl;
  return 0;
}