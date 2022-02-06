/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2019 18:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 12000 KB                             
*  problem: https://codeforces.com/contest/803/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2],bc[N+2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  fr[0]=1e9;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]==0)fr[i]=0;
    else fr[i]=fr[i-1]+1;
  }
  bc[n+1]=1e9;
  for(int i=n;i>=1;i--)
  {
    if(aa[i]==0)bc[i]=0;
    else bc[i]=bc[i+1]+1;
  }
  for(int i=1;i<=n;i++)
    cout<<min(fr[i],bc[i])<<" ";
  cout<<endl;
  return 0;
}