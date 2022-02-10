/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-15 20:40:53                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1131
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,q;
long arr[7],mod,n;
struct matrix
{
  long mat[7][7];
  matrix()
  {
    memset(mat,0,sizeof(mat));
  }
};
matrix multiply(matrix a,matrix b)
{
  matrix c;
  for(int i=1;i<=6;i++)
  {
    for(int j=1;j<=6;j++)
    {
      c.mat[i][j]=0;
      for(int k=1;k<=6;k++)
      {
        c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
      }
    }
  }
  return c;
}
matrix bigmod(int x,matrix base)
{
  matrix ret;
  for(int i=1;i<=6;i++)
    for(int j=1;j<=6;j++)
    {
      if(i==j)ret.mat[i][j]=1;
      else ret.mat[i][j]=0;
    }
  while(x)
  {
    if(x&1)ret=multiply(ret,base);
    base=multiply(base,base);
    x/=2;
  }
  return ret;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    matrix base;
    scanf("%lld%lld%lld",&base.mat[1][1],&base.mat[1][2],&base.mat[1][6]);
    scanf("%lld%lld%lld",&base.mat[4][4],&base.mat[4][5],&base.mat[4][3]);
    base.mat[2][1]=1;
    base.mat[3][2]=1;
    base.mat[5][4]=1;
    base.mat[6][5]=1;

    scanf("%lld%lld%lld",&arr[3],&arr[2],&arr[1]);
    scanf("%lld%lld%lld",&arr[6],&arr[5],&arr[4]);

    scanf("%lld",&mod);

    scanf("%d",&q);
    printf("Case %d:\n",++tc);
    while(q--)
    {
      scanf("%lld",&n);

      if(n==0)printf("%lld %lld\n",arr[3],arr[6]);
      else if(n==1)printf("%lld %lld\n",arr[2],arr[5]);
      else if(n==2)printf("%lld %lld\n",arr[1],arr[4]);
      else
      {
        n-=2;
        matrix ret;
        ret=bigmod(n,base);
        long rs1=0,rs2=0;
//        for(int i=1;i<=6;i++)
//        {
//          for(int j=1;j<=6;j++)
//          {
//            cout<<ret.mat[i][j]<<" ";
//          }
//          cout<<endl;
//        }
        for(int i=1;i<=6;i++)
          rs1=(rs1+ret.mat[1][i]*arr[i])%mod;
        for(int i=1;i<=6;i++)
          rs2=(rs2+ret.mat[4][i]*arr[i])%mod;
        printf("%lld %lld\n",rs1,rs2);
      }
    }
  }
  return 0;
}