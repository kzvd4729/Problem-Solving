/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-31 21:20:42                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 4                                          memory_used (MB): 4.5                             
*  problem: https://vjudge.net/problem/LightOJ-1106
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int f[N+2],d[N+2],ed[N+2],n,dp[26][194],pth[26][194];
int dfs(int i,int m)
{
  if(m<=0||i>n)return 0;
  if(dp[i][m]!=-1)return dp[i][m];
  int now=dfs(i+1,m-ed[i]);

  pth[i][m]=0;

  int in=f[i],sm=0;
  for(int cnt=1;cnt<=m;cnt++)
  {
    sm+=max(in,0);
    int ok=sm+dfs(i+1,m-cnt-ed[i]);
    //if(i==1)cout<<cnt<<" --> "<<ok<<endl;
    if(ok>=now)
      now=ok,pth[i][m]=cnt;
    in-=d[i];//if(in<=0)break;
  }
  return dp[i][m]=now;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int h;cin>>n>>h;h*=12;
    for(int i=1;i<=n;i++)cin>>f[i];
    for(int i=1;i<=n;i++)cin>>d[i];

    for(int i=1;i<n;i++)cin>>ed[i];ed[n]=0;

    memset(dp,-1,sizeof(dp));
    int ans=dfs(1,h),tm=h;
    cout<<"Case "<<++tc<<":\n";
    for(int i=1;i<=n;i++)
    {
      if(i>1)cout<<", ";
      if(tm<=0)
      {
        cout<<0;continue;
      }
      cout<<pth[i][tm]*5;
      tm-=(pth[i][tm]+ed[i]);
    }
    cout<<"\n";
    cout<<"Number of fish expected: "<<ans<<"\n";
  }
  return 0;
}