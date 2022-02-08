/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-11 10:00:25                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 58 ms                                           memory_used: 512 KB                               
*  problem: https://atcoder.jp/contests/dp/tasks/dp_r
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************** Matrix Expo **************/
const int M=50;
const long Mod=1e9+7;
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
  int n;long k;cin>>n>>k;matrix b;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>b.m[i][j];
  b=Expo(k,b,n);long ans=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      ans=(ans+b.m[i][j])%Mod;
  cout<<ans<<endl;
   return 0;
}