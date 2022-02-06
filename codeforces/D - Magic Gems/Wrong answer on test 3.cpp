/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/18/2019 23:32                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1117/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************** Matrix Expo **************/
const int M=100;
const long Mod=1000000007;
struct matrix
{
  long m[M+2][M+2];
  matrix()
  {
    memset(m,0,sizeof(m));
  }
};
matrix Multiply(matrix a,matrix b,int n)
{
  matrix c;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      for(int k=1;k<=n;k++)
        c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%Mod;
  return c;
}
matrix Expo(long x,matrix b,int n)
{
  matrix r;//if(x<0)assert(0);
  for(int i=1;i<=n;i++)r.m[i][i]=1;
  while(x)
  {
    if(x&1)r=Multiply(r,b,n);
    b=Multiply(b,b,n);x/=2;
  }
  return r;
}
//matrix*column_vector=function_column_vector
///////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
  if(m>n)cout<<1<<endl,exit(0);
  matrix bs;
  bs.m[1][1]=1;bs.m[1][m]=1;
  for(int i=2;i<=m;i++)bs.m[i][i-1]=1;
  bs=Expo(n-m,bs,m);
  /*for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cout<<bs.m[i][j]<<" ";
    }
    cout<<endl;
  }*/
  cout<<bs.m[1][1]*2+bs.m[1][m]<<endl;
   return 0;
}