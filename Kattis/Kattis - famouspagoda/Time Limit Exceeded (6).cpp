/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 21:46:40                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-famouspagoda
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e18;
long aa[N+2],sqm[N+2],nqm[N+2];
long dp[2000+2][2000+2],mt[2000+2][2000+2];

long ck2(long i,long j,long md)
{
  long ret=sqm[j]-sqm[i-1]+(j-i+1)*md*md;
  ret-=2*md*(nqm[j]-nqm[i-1]);
  return ret;
}
void case2(long n,long g)
{
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=n;j++)mt[i][j]=inf;
  }
  for(long i=1;i<=n;i++)
  {
    sqm[i]=sqm[i-1]+aa[i]*aa[i];
    nqm[i]=nqm[i-1]+aa[i];
  }
  for(long i=1;i<=n;i++)
  {
    for(long j=i;j>=1;j--)
    {
      long lo=0,hi=1e6,md1,md2;
      while(hi-lo>3)
      {
        md1=(lo+lo+hi)/3,md2=(lo+hi+hi)/3;
        if(ck2(j,i,md1)<ck2(j,i,md2))hi=md2;
        else lo=md1;
      }
      for(long md=lo;md<=hi;md++)
      {
        mt[j][i]=min(mt[j][i],ck2(j,i,md));
      }
    }
  }
}
vector<long>v[N+2],q[N+2];
long ck1(long i,long j,long md)
{
  long sml=0,s=0;
  long id=upper_bound(v[j].begin(),v[j].end(),md)-v[j].begin();
  id--;
  if(id>=0)sml=q[j][id],s=id+1;

  id=upper_bound(v[i-1].begin(),v[i-1].end(),md)-v[i-1].begin();
  id--;
  if(id>=0)sml-=q[i-1][id],s-=(id+1);

  long big=nqm[j]-nqm[i-1]-sml;
  //cout<<i<<" "<<j<<" "<<nqm[j]-nqm[i-1]<<" "<<md<<endl,exit(0);
  return big-md*(j-i+1-s)+md*s-sml;
}
void case1(long n,long g)
{
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=n;j++)mt[i][j]=inf;
  }
  for(long i=1;i<=n;i++)
    nqm[i]=nqm[i-1]+aa[i];
  for(long i=1;i<=n;i++)
  {
    v[i]=v[i-1];v[i].push_back(aa[i]);
    sort(v[i].begin(),v[i].end());
    for(long j=0;j<v[i].size();j++)
    {
      if(j==0)q[i].push_back(v[i][j]);
      else q[i].push_back(q[i].back()+v[i][j]);
    }
  }
  for(long i=1;i<=n;i++)
  {
    for(long j=i;j>=1;j--)
    {
      long lo=0,hi=1e6,md1,md2;
      while(hi-lo>3)
      {
        md1=(lo+lo+hi)/3,md2=(lo+hi+hi)/3;
        if(ck1(j,i,md1)<ck1(j,i,md2))hi=md2;
        else lo=md1;
      }
      for(long md=lo;md<=hi;md++)
      {
        mt[j][i]=min(mt[j][i],ck1(j,i,md));
      }
    }
  }
}
void dfs(long i,long lo,long hi,long lt,long rt)
{
  if(lo>hi)return ;
  long j=(lo+hi)>>1;long &mn=dp[i][j],op;
  for(long k=lt,r=min(j,rt);k<=r;k++)
  {
    long now=mt[k][j]+dp[i-1][k-1];
    if(now<mn)mn=now,op=k;
  }
  dfs(i,lo,j-1,lt,op);dfs(i,j+1,hi,op,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,g,k;cin>>n>>g>>k;
  for(long i=1;i<=n;i++)cin>>aa[i];

  if(k==1)case1(n,g);else case2(n,g);

  /*for(long i=1;i<=n;i++)
  {
    for(long j=i;j<=n;j++)
    {
      cout<<mt[i][j]<<" ";
    }
    cout<<endl;
  }*/
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)dp[i][j]=inf;
  }
  dp[0][0]=0;
  for(int i=1;i<=g;i++)dfs(i,1,n,1,n);
  cout<<dp[g][n]<<endl;
  return 0;
}