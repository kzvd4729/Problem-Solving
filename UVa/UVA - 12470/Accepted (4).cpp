/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-09 14:55:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12470
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************** Matrix Expo **************/
const int M=3;
const long Mod=1e9+9;
struct matrix
{
  long m[M+2][M+2];
  matrix()
  {
    memset(m,0,sizeof(m));
  }
};
matrix Multiply(matrix a,matrix b)
{
  matrix c;
  for(int i=1;i<=M;i++)
    for(int j=1;j<=M;j++)
      for(int k=1;k<=M;k++)
        c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%Mod;
  return c;
}
matrix Bigmod(long x,matrix b)
{
  matrix r;//if(x<0)assert(0);
  for(int i=1;i<=M;i++)r.m[i][i]=1;
  while(x)
  {
    if(x&1)r=Multiply(r,b);
    b=Multiply(b,b);x/=2;
  }
  return r;
}
//matrix*column_vector=function_column_vector
///////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;
  while(cin>>n)
  {
    if(!n)break;
    if(n==1)cout<<0<<"\n";
    else if(n==2)cout<<1<<"\n";
    else if(n==3)cout<<2<<"\n";
    else
    {
      matrix b;b.m[1][1]=1;b.m[1][2]=1;
      b.m[1][3]=1;b.m[2][1]=1;b.m[3][2]=1;
      b=Bigmod(n-3,b);
      cout<<(2*b.m[1][1]+b.m[1][2])%Mod<<"\n";
    }
  }
  return 0;
}