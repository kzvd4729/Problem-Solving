/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-28 14:57:29                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 5                                          memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1198
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int aa[N+2],bb[N+2];

/**************** Hungarian Algorithm ******************/
const int INF=1e9;
int Hun[N+2][N+2];
int Hungarian(int n,int m)
{
  vector<int>u(n+1),v(m+1),p(m+1),way(m+1);
  for(int i=1;i<=n;i++)
  {
    p[0]=i;int j0=0;
    vector<int>minv(m+1,INF);
    vector<char>used(m+1,false);
    do
    {
      used[j0]=true;int i0=p[j0],delta=INF,j1;
      for(int j=1;j<=m;j++)
      {
        if(!used[j])
        {
          int cur=Hun[i0][j]-u[i0]-v[j];
          if(cur<minv[j])minv[j]=cur,way[j]=j0;
          if(minv[j]<delta)delta=minv[j],j1=j;
        }
      }
      for(int j=0;j<=m;j++)
      {
        if(used[j])u[p[j]]+=delta,v[j]-=delta;
        else minv[j]-=delta;
      }
      j0=j1;
    }while(p[j0]!=0);
    do 
    {
      int j1=way[j0];p[j0]=p[j1];
      j0=j1;
    }while(j0);
  }
  int ret=0;
  for(int i=1;i<=m;i++)ret+=Hun[p[i]][i];
  return ret;
}
//////////////////////////////////////////////////////////

int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&aa[i]);
    for(int i=1;i<=n;i++)
      scanf("%d",&bb[i]);
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(aa[i]>bb[j])Hun[i][j]=-2;
        else if(aa[i]==bb[j])Hun[i][j]=-1;
        else Hun[i][j]=0;
      }
    }
    printf("Case %d: %d\n",++tc,-Hungarian(n,n));
  }
  return 0;
}