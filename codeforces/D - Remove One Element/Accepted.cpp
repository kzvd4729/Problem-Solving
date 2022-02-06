/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/12/2019 19:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/1272/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],fr[N+2],rv[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int mx=1;
   fr[1]=1;
  for(int i=2;i<=n;i++)
  {
    if(aa[i]>aa[i-1])fr[i]=fr[i-1]+1;
    else fr[i]=1;
    mx=max(mx,fr[i]);
  }
  rv[n]=1;
  for(int i=n-1;i>=1;i--)
  {
    if(aa[i]<aa[i+1])rv[i]=rv[i+1]+1;
    else rv[i]=1;
     mx=max(mx,rv[i]);
  }
  for(int i=2;i<n;i++)
  {
    if(aa[i-1]<aa[i+1])
      mx=max(mx,fr[i-1]+rv[i+1]);
  }
  cout<<mx<<endl;
  return 0;
}