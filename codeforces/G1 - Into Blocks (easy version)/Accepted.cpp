/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2019 20:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/1209/problem/G1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],mx[N+2],fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];fr[aa[i]]++;
    mx[aa[i]]=max(mx[aa[i]],i);
  }
  int ans=0;
  for(int i=1;i<=n; )
  {
    int pt=mx[aa[i]],j,mxfr=fr[aa[i]];
    for(j=i+1;j<=pt;j++)
      pt=max(pt,mx[aa[j]]),mxfr=max(mxfr,fr[aa[j]]);
    ans+=j-i-mxfr;
    i=j;
  }
  cout<<ans<<endl;
  return 0;
}