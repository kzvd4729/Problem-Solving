/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-15 18:48:57                      
*  solution_verdict: Compilation Error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1180
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int xx[N+2],yy[N+2],n,m,md;
bitset<102>vis[102][102];
void dfs(int i,int m1,int m2)
{
  if(m1<0)m1=0;if(m2<0)m2=0;
  if(!m1&&!m2)
  {
    f=1;return ;
  }
  if(i>n)return ;
  if(vis[i][m1][m2])return ;
  vis[i][m1][m2]=1;

  dfs(i+1,m1-(md/xx[i]),m2);
  dfs(i+1,m1,m2-(md/yy[i]));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>xx[i]>>yy[i];
    int lo=1,hi=50000;
    while(lo<hi)
    {
      md=(lo+hi)/2;
      for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
          vis[i][j].reset();
      int f=0;dfs(1,m,m);
      if(f)hi=md;else lo=md;
    }
  }
  return 0;
}