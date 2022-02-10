/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-09 14:33:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 61                                         memory_used (MB): 9.9                             
*  problem: https://vjudge.net/problem/LightOJ-1065
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long arr[N+2],mod;
/************** Matrix Expo **************/
const int M=2;
long Mod=1e9+7;
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
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int a,b,n,m;scanf("%d%d%d%d",&a,&b,&n,&m);
    Mod=1;while(m--)Mod*=10;
    if(n<=1)
    {
      if(n==0)printf("Case %d: %d\n",++tc,a%Mod);
      else printf("Case %d: %d\n",++tc,b%Mod);
      continue;
    }
    matrix bs;bs.m[1][1]=1;bs.m[1][2]=1;bs.m[2][1]=1;
    bs=Bigmod(n-1,bs);
    printf("Case %d: %lld\n",++tc,(b*bs.m[1][1]+a*bs.m[1][2])%Mod);
  }
  return 0;
}