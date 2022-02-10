/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 19:01:50                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-engaging
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=1e9;

const int INF=1e9;
int Hun[N+2][N+2];
void Hungarian(int n,int m)
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
  int ret=0,cnt=0;
  for(int i=1;i<=m;i++)
  {
    ret+=Hun[p[i]][i];
    if(p[i])cnt++;
  }
  cout<<-ret<<"\n"<<cnt<<"\n";
  for(int i=1;i<=m;i++)
    if(p[i])cout<<p[i]<<" "<<i<<"\n";
  
  return ;
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=k;i++)
  {
    int a,b,c;cin>>a>>b>>c;
    Hun[a][b]=-c;
  }
  Hungarian(m,n);

  return 0;
}