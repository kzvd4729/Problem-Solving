/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-21 13:49:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 13                                         memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1237
****************************************************************************************/
#include<bits/stdc++.h>
#define long long
using namespace std;
const int N=50,inf=1e9;
int aa[N+2],bb[N+2];

int cost[N+2][N+2];
int hungarian(int n,int m)
{
  vector<int>u(n+1),v(m+1),p(m+1),way(m+1);
  for(int i=1;i<=n;i++)
  {
    p[0]=i;int j0=0;
    vector<int>minv(m+1,inf);
    vector<char>used(m+1,false);
    do
    {
      used[j0]=true;int i0=p[j0],delta=inf,j1;
      for(int j=1;j<=m;j++)
      {
        if(!used[j])
        {
          int cur=cost[i0][j]-u[i0]-v[j];
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
  for(int i=1;i<=m;i++)ret+=cost[p[i]][i];
  return ret;
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);

  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,k,g;cin>>n>>k>>g;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)cin>>bb[i];
    sort(aa+1,aa+n+1);sort(bb+1,bb+n+1);
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(bb[j]>aa[i])
          cost[i][j]=min(g,abs(bb[j]-aa[i]-k)*abs(bb[j]-aa[i]-k));
        else cost[i][j]=500001;
      }
    }
    cout<<"Case "<<++tc<<": ";
    int mn=hungarian(n,n);
    if(mn>=500001)
    {
      cout<<"impossible\n";continue;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(bb[j]>aa[i])
          cost[i][j]=-min(g,abs(bb[j]-aa[i]-k)*abs(bb[j]-aa[i]-k));
        else cost[i][j]=500001;

        //Hun[i][j]*=-1;
      }
    }
    cout<<mn<<" "<<-hungarian(n,n)<<"\n";
  }
  return 0;
}