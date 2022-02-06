/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/09/2020 13:41                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1333/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
int mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;if(n<=3)cout<<-1<<endl,exit(0);
  mt[1][1]=4;mt[1][2]=3;mt[1][3]=6;mt[1][4]=12;
  mt[2][1]=7;mt[2][2]=5;mt[2][3]=9;mt[2][4]=15;
  mt[3][1]=14;mt[3][2]=1;mt[3][3]=11;mt[3][4]=10;
  mt[4][1]=13;mt[4][2]=8;mt[4][3]=16;mt[4][4]=2;
   for(int i=1;i<=4;i++)
  {
    for(int j=1;j<=4;j++)
      mt[i][j]+=n*n-16;
  }
  int now=0,in,f;
  for(int j=5;j<=n;j++)
  {
    if((n-j)%2==0)in=1,f=1;
    else in=n,f=-1;
    for(int i=in;i<=n&&i>=1;i+=f)
      mt[i][j]=++now;
  }
  for(int i=n;i>4;i--)mt[i][1]=++now;
  for(int i=5;i<=n;i++)mt[i][3]=++now;
  for(int i=n;i>4;i--)mt[i][4]=++now;
  for(int i=5;i<=n;i++)mt[i][2]=++now;
      for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      cout<<setw(3)<<mt[i][j]<<" ";
    cout<<endl;
  }
   return 0;
}