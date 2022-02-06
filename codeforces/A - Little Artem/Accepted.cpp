/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/09/2020 10:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1333/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    cout<<'W';
    for(int j=2;j<=m;j++)cout<<'B';
    cout<<'\n';
    for(int i=2;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cout<<'B';
      cout<<'\n';
    }
  }
  return 0;
}