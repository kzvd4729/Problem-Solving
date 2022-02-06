/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2019 21:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1266/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2,inf=1e9;
int row[N+2],col[N+2],mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  if(n==1&&m==1)cout<<"0\n",exit(0);
  if(n==1)
  {
    for(int i=2;i<=m+1;i++)
      cout<<i<<" ";
    cout<<"\n",exit(0);
  }
  if(m==1)
  {
    for(int i=2;i<=n+1;i++)
      cout<<i<<"\n";
    exit(0);
  }
  for(int i=1;i<=n;i++)row[i]=i;
  for(int i=1;i<=m;i++)col[i]=n+i;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      mt[i][j]=row[i]*col[j];
      cout<<mt[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}