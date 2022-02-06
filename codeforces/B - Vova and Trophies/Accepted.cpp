/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/28/2018 21:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/1082/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  string s;cin>>s;
  for(int i=1;i<=n;i++)
  {
    qm[i]=qm[i-1];
    if(s[i-1]=='G')
      qm[i]++;
  }
  int gl=qm[n],ans=0;
  if(gl==n)cout<<gl<<endl,exit(0);
  for(int i=1;i<=n;i++)
  {
    int lo=i,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if((md-i+1)-(qm[md]-qm[i-1])<=1)lo=md;
      else hi=md;
    }
    for(md=lo;md<=hi;md++)
    {
      if((md-i+1)-(qm[md]-qm[i-1])>1)break;
    }
    md--;
    int here=qm[md]-qm[i-1];
    if(here==gl)
      ans=max(ans,here);
    else ans=max(ans,here+1);
  }
  cout<<ans<<endl;
  return 0;
}