/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/13/2019 19:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1148/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
void no(void){cout<<-1<<endl,exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,ta,tb,k;cin>>n>>m>>ta>>tb>>k;
  for(int i=1;i<=n;i++)cin>>aa[i],aa[i]+=ta;
  for(int i=1;i<=m;i++)cin>>bb[i];
  if(k>=n)no();int pt=1,mx=-1;
  for(int i=1;i<=k+1;i++)
  {
    while(true)
    {
      if(pt>m)no();
      if(bb[pt]<aa[i])pt++;
      else break;
    }
    if(pt+k+1-i>m)no();
    mx=max(mx,bb[pt+k+1-i]);
  }
  cout<<mx+tb<<endl;
  return 0;
}