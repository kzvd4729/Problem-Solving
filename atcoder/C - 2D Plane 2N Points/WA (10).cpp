/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-17 19:04:15                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2103 ms                                         memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc091/tasks/arc092_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int ans,vis[102],n;
struct point
{
  int x,y;
}r[102],b[102];
void dfs(int one,int cnt)
{
  ans=max(ans,cnt);
  if(one>n)return ;
  for(int i=1;i<=n;i++)
  {
    if(r[one].x<b[i].x&&r[one].y<b[i].y&&vis[i]==0)
    {
      vis[i]=1;
      dfs(one+1,cnt+1);
      vis[i]=0;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>r[i].x>>r[i].y;
  for(int i=1;i<=n;i++)cin>>b[i].x>>b[i].y;
  dfs(1,0);
  cout<<ans<<endl;
  return 0;
}