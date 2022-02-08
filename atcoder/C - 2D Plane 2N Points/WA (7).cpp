/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-17 19:20:35                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc091/tasks/arc092_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int dp[102][102],n,ans,vis[102];
struct point
{
  int x,y;
}r[102],b[102];
bool cmp(point A,point B)
{
  return max(A.x,A.y)>max(B.x,B.y);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>r[i].x>>r[i].y;
  for(int i=1;i<=n;i++)cin>>b[i].x>>b[i].y;
  sort(r+1,r+n+1,cmp);
  sort(b+1,b+n+1,cmp);
 //  for(int i=1;i<=n;i++)
//  {
//    cout<<r[i].x<<" "<<r[i].y<<endl;
//  }
//  for(int i=1;i<=n;i++)
//  {
//    cout<<b[i].x<<" "<<b[i].y<<endl;
//  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(r[i].x<b[j].x&&r[i].y<b[j].y&&vis[j]==0)
      {
        ans++;
        vis[j]=1;
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}