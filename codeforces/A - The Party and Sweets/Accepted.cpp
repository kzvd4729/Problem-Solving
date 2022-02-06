/****************************************************************************************
*  @author: kzvd4729                                         created: May/12/2019 20:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1158/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;int mx=0,mn=1e9;long ans=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];ans+=((aa[i]*1LL)*m);
    mx=max(mx,aa[i]);
  }
  for(int i=1;i<=m;i++)
  {
    cin>>bb[i];
    mn=min(mn,bb[i]);
  }
  if(mx>mn)cout<<-1<<endl,exit(0);
  sort(aa+1,aa+n+1);sort(bb+1,bb+m+1);
  if(n==1)
  {
    if(bb[1]!=aa[1])cout<<-1<<endl,exit(0);
    if(bb[m]!=aa[1])cout<<-1<<endl,exit(0);
  }
  for(int i=2;i<=m;i++)
    ans+=(bb[i]-aa[n])*1LL;
  if(bb[1]!=aa[n])
    ans+=(bb[1]-aa[n-1])*1LL;
  cout<<ans<<endl;
  return 0;
}