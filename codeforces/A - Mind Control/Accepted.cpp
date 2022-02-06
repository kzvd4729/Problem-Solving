/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/04/2020 18:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1290/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;m--;k=min(k,m);
    for(int i=1;i<=n;i++)cin>>aa[i];
    int ans=0;
    for(int i=0;i<=k;i++)
    {
      int now=1e9;
      for(int j=0;j<=m-k;j++)
        now=min(now,max(aa[1+i+j],aa[n-m+i+j]));
      ans=max(ans,now);
    }
    cout<<ans<<"\n";
  }
  return 0;
}