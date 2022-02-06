/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/28/2019 14:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 312 ms                                          memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/1107/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e2;
long aa[N+2],bb[N+2],kk[N+2];
 /**************** Hungarian Algorithm ******************/
const long INF=1e18;
long Hun[N+2][N+2];
long Hungarian(long n,long m)
{
  vector<long>u(n+1),v(m+1),p(m+1),way(m+1);
  for(long i=1;i<=n;i++)
  {
    p[0]=i;long j0=0;
    vector<long>minv(m+1,INF);
    vector<char>used(m+1,false);
    do
    {
      used[j0]=true;long i0=p[j0],delta=INF,j1;
      for(long j=1;j<=m;j++)
      {
        if(!used[j])
        {
          long cur=Hun[i0][j]-u[i0]-v[j];
          if(cur<minv[j])minv[j]=cur,way[j]=j0;
          if(minv[j]<delta)delta=minv[j],j1=j;
        }
      }
      for(long j=0;j<=m;j++)
      {
        if(used[j])u[p[j]]+=delta,v[j]-=delta;
        else minv[j]-=delta;
      }
      j0=j1;
    }while(p[j0]!=0);
    do 
    {
      long j1=way[j0];p[j0]=p[j1];
      j0=j1;
    }while(j0);
  }
  long ret=0;
  for(long i=1;i<=m;i++)ret+=Hun[p[i]][i];
  return ret;
}
//////////////////////////////////////////////////////////
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)
    cin>>aa[i]>>bb[i]>>kk[i];
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=n;j++)
    {
      Hun[i][j]=aa[i]-bb[i]*min(j-1,kk[i]);
      if(Hun[i][j]<0)Hun[i][j]=0;
      else Hun[i][j]*=-1;
    }
  }
  cout<<-Hungarian(n,n)<<endl;
  return 0;
}