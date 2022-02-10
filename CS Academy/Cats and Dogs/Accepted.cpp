/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 17 ms                                           memory_used: 660 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,cnt[2002];
struct data
{
  int x,y;
}ct[2002],dg[2002];
int dist(int i,int j)
{
  return (dg[i].x-ct[j].x)*(dg[i].x-ct[j].x)+(dg[i].y-ct[j].y)*(dg[i].y-ct[j].y);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>ct[i].x>>ct[i].y;
  for(int i=1;i<=m;i++)
    cin>>dg[i].x>>dg[i].y;
  for(int i=1;i<=m;i++)
  {
    int mn=1e9,id;
    for(int j=1;j<=n;j++)
    {
      int ret=dist(i,j);
      if(ret<mn)
      {
        mn=ret;
        id=j;
      }
    }
    cnt[id]++;
  }
  int ans=0;
  for(int i=1;i<=n;i++)
    if(cnt[i]==1)ans++;
  cout<<ans<<endl;
  return 0;
}