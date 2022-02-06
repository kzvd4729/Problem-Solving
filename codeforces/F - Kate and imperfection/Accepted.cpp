/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/09/2020 11:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/1333/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+i;j<=n;j+=i)v[j]=max(v[j],i);
  }
  sort(v+1,v+n+1);
  for(int i=2;i<=n;i++)cout<<v[i]<<" ";
  cout<<endl;
  return 0;
}