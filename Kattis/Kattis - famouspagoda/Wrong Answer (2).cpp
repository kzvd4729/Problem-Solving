/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-13 18:20:51                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-famouspagoda
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long inf=1e18;
long aa[N+2],sqm[N+2],nqm[N+2];
long dp[2000+2][2000+2],mt[2000+2][2000+2];

inline long ck2(int i,int j,long md)
{
  long ret=sqm[j]-sqm[i-1]+(j-i+1)*md*md;
  ret-=2*md*(nqm[j]-nqm[i-1]);
  return ret;
}
void case2(int n,int g)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)mt[i][j]=inf;
  }
  for(int i=1;i<=n;i++)
  {
    sqm[i]=sqm[i-1]+aa[i]*aa[i];
    nqm[i]=nqm[i-1]+aa[i];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=i;j>=1;j--)
    {
      int lo=0,hi=1e6,md1,md2;
      while(hi-lo>2)
      {
        md1=(lo+lo+hi)/3,md2=(lo+hi+hi)/3;
        if(ck2(j,i,md1)<ck2(j,i,md2))hi=md2;
        else lo=md1;
      }
      for(int md=lo;md<=hi;md++)
      {
        mt[j][i]=min(mt[j][i],ck2(j,i,md));
      }
    }
  }
}
vector<int>v[N+2],q[N+2];
inline int ck1(int i,int j,int md)
{
  int sml=0,s=0;
  int id=upper_bound(v[j].begin(),v[j].end(),md)-v[j].begin();
  id--;
  if(id>=0)sml=q[j][id],s=id+1;

  id=upper_bound(v[i-1].begin(),v[i-1].end(),md)-v[i-1].begin();
  id--;
  if(id>=0)sml-=q[i-1][id],s-=(id+1);

  int big=nqm[j]-nqm[i-1]-sml;
  //cout<<i<<" "<<j<<" "<<nqm[j]-nqm[i-1]<<" "<<md<<endl,exit(0);
  return big-md*(j-i+1-s)+md*s-sml;
}
void case1(int n,int g)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)mt[i][j]=inf;
  }
  for(int i=1;i<=n;i++)
    nqm[i]=nqm[i-1]+aa[i];
  for(int i=1;i<=n;i++)
  {
    v[i]=v[i-1];v[i].push_back(aa[i]);
    sort(v[i].begin(),v[i].end());
    for(int j=0;j<v[i].size();j++)
    {
      if(j==0)q[i].push_back(v[i][j]);
      else q[i].push_back(q[i].back()+v[i][j]);
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=i;j>=1;j--)
    {
      int md=(i+j)/2;
      mt[j][i]=nqm[i]-nqm[md]-(nqm[md]-nqm[j-1])-aa[md]*(i-md)+aa[md]*(md-j+1);
    }
  }
} 
void dfs(int i,int lo,int hi,int lt,int rt)
{
  if(lo>hi)return ;
  int j=(lo+hi)>>1;long &mn=dp[i][j],op;
  for(int k=lt,r=min(j,rt);k<=r;k++)
  {
    long now=mt[k][j]+dp[i-1][k-1];
    if(now<mn)mn=now,op=k;
  }
  dfs(i,lo,j-1,lt,op);dfs(i,j+1,hi,op,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,g,k;cin>>n>>g>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];

  if(k==1)case1(n,g);else case2(n,g);
  /*for(int i=1;i<=n;i++)
  {
    for(int j=i;j<=n;j++)
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