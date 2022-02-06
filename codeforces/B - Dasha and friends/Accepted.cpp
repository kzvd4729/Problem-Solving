/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/01/2018 19:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/761/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=n;i++)
    cin>>b[i];
  for(int i=n+1;i<=n+n;i++)
    a[i]=a[i-n]+m;
  for(int i=1;i<=n;i++)
  {
    int f=0;
    for(int j=i+1;j<n+i;j++)
    {
      if(a[j]-a[j-1]!=b[j-i+1]-b[j-i])
        f=1;
    }
    if(f==0)cout<<"YES"<<endl,exit(0);
  }
  cout<<"NO"<<endl;
  return 0;
}