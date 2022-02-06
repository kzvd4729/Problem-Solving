/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2019 18:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/803/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(k==0)break;
      if(mt[i][j])continue;
      if(i==j)
      {
        mt[i][j]=1;k--;
      }
      else if(k>=2)
      {
        mt[i][j]=1;mt[j][i]=1;
        k-=2;
      }
    }
  }
  if(k)cout<<-1<<endl,exit(0);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout<<mt[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}