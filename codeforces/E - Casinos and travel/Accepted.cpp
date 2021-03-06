/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2019 19:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/852/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int pw[N+2],dg[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(pw[i-1]*2)%mod;
   int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;dg[u]++,dg[v]++;
  }
  int lf=0;
  for(int i=1;i<=n;i++)if(dg[i]==1)lf++;
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(dg[i]==1)ans+=pw[n-lf+1];
    else ans+=pw[n-lf];
    ans%=mod;
  }
  cout<<ans<<endl;
  return 0;
}