/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-21 01:57:27                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1237
****************************************************************************************/
#include<bits/stdc++.h>
//#define long long long long long long
using namespace std;
const long long N=1000,inf=1e15;
long long aa[N+2],bb[N+2];

long long Hun[N+2][N+2];
long long C=50000;
long long Hungarian(long long n,long long m)
{
  vector<long long>u(n+1),v(m+1),p(m+1),way(m+1);
  for(long long i=1;i<=n;i++)
  {
    p[0]=i;long long j0=0;
    vector<long long>minv(m+1,inf);
    vector<char>used(m+1,false);
    do
    {
      used[j0]=true;long long i0=p[j0],delta=inf,j1;
      for(long long j=1;j<=m;j++)
      {
        if(!used[j])
        {
          long long cur=Hun[i0][j]-u[i0]-v[j];
          if(cur<minv[j])minv[j]=cur,way[j]=j0;
          if(minv[j]<delta)delta=minv[j],j1=j;
        }
      }
      for(long long j=0;j<=m;j++)
      {
        if(used[j])u[p[j]]+=delta,v[j]-=delta;
        else minv[j]-=delta;
      }
      j0=j1;
    }while(p[j0]!=0);
    do 
    {
      long long j1=way[j0];p[j0]=p[j1];
      j0=j1;
    }while(j0);
  }
  long long ret=0;
  for(long long i=1;i<=m;i++)ret+=Hun[p[i]][i];
  return ret;
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);

  long long t,tc=0;cin>>t;
  while(t--)
  {
    long long n,k,g;cin>>n>>k>>g;
    for(long long i=1;i<=n;i++)cin>>aa[i];
    for(long long i=1;i<=n;i++)cin>>bb[i];
    sort(aa+1,aa+n+1);sort(bb+1,bb+n+1);
    for(long long i=1;i<=n;i++)
    {
      for(long long j=1;j<=n;j++)
      {
        if(bb[j]>aa[i])
          Hun[i][j]=min(g,abs(bb[j]-aa[i]-k)*abs(bb[j]-aa[i]-k));
        else Hun[i][j]=1e8;
      }
    }
    cout<<"Case "<<++tc<<": ";
    long long mn=Hungarian(n,n);
    if(mn>=1e8)
    {
      cout<<"impossible\n";continue;
    }
    for(long long i=1;i<=n;i++)
    {
      for(long long j=1;j<=n;j++)
      {
        if(bb[j]>=aa[i])
          Hun[i][j]=C-min(g,Hun[i][j]=min(g,abs(bb[j]-aa[i]-k)*abs(bb[j]-aa[i]-k)));
        else Hun[i][j]=1e8;

        //Hun[i][j]*=-1;
      }
    }
    cout<<mn<<" "<<C*n-Hungarian(n,n)<<"\n";
  }
  return 0;
}