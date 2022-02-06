/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/01/2018 20:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/761/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=1e5;
int a[N+2],c[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,l,r;cin>>n>>l>>r;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    c[x]=i;
  }
  int pre=-inf;
  for(int i=1;i<=n;i++)
  {
    int mn=max(l,pre+a[c[i]]+1);
    if(mn>r)cout<<-1<<endl,exit(0);
    b[c[i]]=mn;pre=b[c[i]]-a[c[i]];
  }
  for(int i=1;i<=n;i++)
    cout<<b[i]<<" ";
  cout<<endl;
  return 0;
}