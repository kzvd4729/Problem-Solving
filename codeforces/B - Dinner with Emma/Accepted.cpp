/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2019 15:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/616/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;int mx=0;
  for(int i=1;i<=n;i++)
  {
    int mn=1e9;
    for(int j=1;j<=m;j++)
    {
      int x;cin>>x;mn=min(mn,x);
    }
    mx=max(mx,mn);
  }
  cout<<mx<<endl;
  return 0;
}