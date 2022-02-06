/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 18:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/509/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int mt[10+2][10+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    mt[i][1]=mt[1][i]=1;
  for(int i=2;i<=n;i++)
  {
    for(int j=2;j<=n;j++)
      mt[i][j]=mt[i-1][j]+mt[i][j-1];
  }
  cout<<mt[n][n]<<endl;
    return 0;
}