/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-09 10:43:18                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 208                                        memory_used (MB): 9.9                             
*  problem: https://vjudge.net/problem/LightOJ-1131
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long arr[N+2],mod;
/************ Matrix Expo ************/
const int M=6;
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
        c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
  return c;
}
matrix Bigmod(long x,matrix b)
{
  matrix r;
  for(int i=1;i<=M;i++)r.m[i][i]=1;
  while(x)
  {
    if(x&1)r=Multiply(r,b);
    b=Multiply(b,b);x/=2;
  }
  return r;
}
///////////////////////////////////////
int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    matrix base;
    scanf("%lld%lld%lld",&base.m[1][1],&base.m[1][2],&base.m[1][6]);
    scanf("%lld%lld%lld",&base.m[4][4],&base.m[4][5],&base.m[4][3]);
    base.m[2][1]=1;
    base.m[3][2]=1;
    base.m[5][4]=1;
    base.m[6][5]=1;

    scanf("%lld%lld%lld",&arr[3],&arr[2],&arr[1]);
    scanf("%lld%lld%lld",&arr[6],&arr[5],&arr[4]);

    scanf("%lld",&mod);

    int q;scanf("%d",&q);
    printf("Case %d:\n",++tc);
    while(q--)
    {
      long n;scanf("%lld",&n);

      if(n==0)printf("%lld %lld\n",arr[3]%mod,arr[6]%mod);
      else if(n==1)printf("%lld %lld\n",arr[2]%mod,arr[5]%mod);
      else if(n==2)printf("%lld %lld\n",arr[1]%mod,arr[4]%mod);
      else
      {
        n-=2;
        matrix ret;
        ret=Bigmod(n,base);
        long rs1=0,rs2=0;
        for(int i=1;i<=6;i++)
          rs1=(rs1+ret.m[1][i]*arr[i])%mod;
        for(int i=1;i<=6;i++)
          rs2=(rs2+ret.m[4][i]*arr[i])%mod;
        printf("%lld %lld\n",rs1%mod,rs2%mod);
      }
    }
  }
  

  return 0;
}