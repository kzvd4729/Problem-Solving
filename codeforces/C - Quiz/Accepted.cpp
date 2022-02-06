/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2018 19:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/337/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+9;
long wr,us,mx,ml,n,m,k,ans;
struct matrix
{
  long mat[3][3];
};
matrix multiply(matrix one,matrix two)
{
  matrix thr;
  for(int i=1;i<=2;i++)
  {
    for(int j=1;j<=2;j++)
    {
      thr.mat[i][j]=0;
      for(int k=1;k<=2;k++)
      {
        thr.mat[i][j]=(thr.mat[i][j]+one.mat[i][k]*two.mat[k][j])%mod;
      }
    }
  }
  return thr;
}
matrix bigmod(matrix base,long p)
{
  matrix ret;
   ret.mat[1][1]=1;
  ret.mat[1][2]=0;
  ret.mat[2][1]=0;
  ret.mat[2][2]=1;
   while(p)
  {
    if(p&1)ret=multiply(base,ret);
    base=multiply(base,base);
    p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>k;
   wr=n-m;
   mx=(k-1)*(wr+1);
   if(mx>=m)cout<<m<<endl,exit(0);
   us=m-mx;
   ml=(us+k-1)/k;
     if(ml==1)cout<<((k*2+m-(ml*k)%mod))%mod<<endl,exit(0);
   matrix base;
  base.mat[1][1]=2;
  base.mat[1][2]=2;
  base.mat[2][1]=0;
  base.mat[2][2]=1;
   base=bigmod(base,ml-1);
   ans=((base.mat[1][1]*k*2)%mod+(base.mat[1][2]*k)%mod+m-k*ml)%mod;
  cout<<ans%mod<<endl;
  return 0;
}