/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-21 13:32:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 10                                         memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1237
****************************************************************************************/
#include<bits/stdc++.h>
#define long long
using namespace std;
const long N=50,inf=1e15;
long aa[N+2],bb[N+2];

long Hun[N+2][N+2];
long Hungarian(long n,long m)
{
  vector<long>u(n+1),v(m+1),p(m+1),way(m+1);
  for(long i=1;i<=n;i++)
  {
    p[0]=i;long j0=0;
    vector<long>minv(m+1,inf);
    vector<char>used(m+1,false);
    do
    {
      used[j0]=true;long i0=p[j0],delta=inf,j1;
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

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);

  long t,tc=0;cin>>t;
  while(t--)
  {
    long n,k,g;cin>>n>>k>>g;
    for(long i=1;i<=n;i++)cin>>aa[i];
    for(long i=1;i<=n;i++)cin>>bb[i];
    sort(aa+1,aa+n+1);sort(bb+1,bb+n+1);
    for(long i=1;i<=n;i++)
    {
      for(long j=1;j<=n;j++)
      {
        if(bb[j]>aa[i])
          Hun[i][j]=min(g,abs(bb[j]-aa[i]-k)*abs(bb[j]-aa[i]-k));
        else Hun[i][j]=100000000;
      }
    }
    cout<<"Case "<<++tc<<": ";
    long mn=Hungarian(n,n);
    if(mn>=100000000)
    {
      cout<<"impossible\n";continue;
    }
    for(long i=1;i<=n;i++)
    {
      for(long j=1;j<=n;j++)
      {
        if(bb[j]>aa[i])
          Hun[i][j]=-min(g,Hun[i][j]=min(g,abs(bb[j]-aa[i]-k)*abs(bb[j]-aa[i]-k)));
        else Hun[i][j]=100000000;

        //Hun[i][j]*=-1;
      }
    }
    cout<<mn<<" "<<-Hungarian(n,n)<<"\n";
  }
  return 0;
}