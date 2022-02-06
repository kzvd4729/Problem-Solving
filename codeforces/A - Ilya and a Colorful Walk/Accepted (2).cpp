/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/11/2019 19:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1119/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int mx,aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int mx=0;
  for(int i=n;i>=1;i--)
    if(aa[i]!=aa[1])
      mx=max(mx,i-1);
  for(int i=1;i<=n;i++)
    if(aa[i]!=aa[n])
      mx=max(mx,n-i);
  cout<<mx<<endl;
  return 0;
}