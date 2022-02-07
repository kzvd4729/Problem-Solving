/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 22:56:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 40                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10870
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long d,n,mod,f[20],a[20];
struct matrix
{
  long mt[16][16];
  matrix()
  {
    memset(mt,0,sizeof(mt));
  }
};
matrix multiply(matrix a,matrix b,int m)
{
  matrix c;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=m;j++)
    {
      for(int k=1;k<=m;k++)
      {
        c.mt[i][j]=(c.mt[i][j]+a.mt[i][k]*b.mt[k][j])%mod;
      }
    }
  }
  return c;
}
matrix bigmod(matrix b,long p,int m)
{
  matrix c;
  for(int i=1;i<=m;i++)c.mt[i][i]=1;
  while(p) 
  {
    if(p%2)c=multiply(c,b,m);
    b=multiply(b,b,m);p/=2;
  }
  return c;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>d>>n>>mod)
  {
    if(!(d+n+mod))break;
    for(int i=1;i<=d;i++)cin>>a[i];
    for(int i=1;i<=d;i++)cin>>f[i];
    if(n<=d)
    {
      cout<<f[n]%mod<<endl;continue;
    }
    matrix b;
    for(int i=1;i<=d;i++)b.mt[1][i]=a[i];
    for(int i=2;i<=d;i++)b.mt[i][i-1]=1;
    b=bigmod(b,n-d,d);
    long ans=0;
    for(int i=1;i<=d;i++)
      ans=(ans+b.mt[1][i]*f[d-i+1])%mod;
    cout<<ans<<endl;
  }
  return 0;
}