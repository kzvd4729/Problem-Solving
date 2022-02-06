/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/24/2019 01:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1216 ms                                         memory_used: 4900 KB                              
*  problem: https://codeforces.com/gym/101972/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2,inf=1e9+1;
int aa[N+2][N+2],on[N+2][N+2],tw[N+2][N+2];
int th[N+2][N+2],fr[N+2][N+2];
void mem(void)
{
  for(int i=0;i<=N+1;i++)
  {
    for(int j=0;j<=N+1;j++)
    {
      on[i][j]=-inf;tw[i][j]=-inf;
      th[i][j]=-inf;fr[i][j]=-inf;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin>>aa[i][j];
      }
    }
    mem();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        on[i][j]=max(on[i][j-1],aa[i][j]);
        on[i][j]=max(on[i][j],on[i-1][j]);
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=m;j>=1;j--)
      {
        tw[i][j]=max(tw[i][j+1],aa[i][j]);
        tw[i][j]=max(tw[i][j],tw[i-1][j]);
      }
    }
    for(int i=n;i>=1;i--)
    {
      for(int j=1;j<=m;j++)
      {
        th[i][j]=max(th[i][j-1],aa[i][j]);
        th[i][j]=max(th[i][j],th[i+1][j]);
      }
    }
    for(int i=n;i>=1;i--)
    {
      for(int j=m;j>=1;j--)
      {
        fr[i][j]=max(fr[i][j+1],aa[i][j]);
        fr[i][j]=max(fr[i][j],fr[i+1][j]);
      }
    }
    int ans=inf;
    for(int i=2;i<n;i++)
    {
      for(int j=2;j<m;j++)
      {
        int mx=0,mn=inf;
        mx=max(mx,on[i-1][j-1]);
        mx=max(mx,tw[i-1][j+1]);
        mx=max(mx,th[i+1][j-1]);
        mx=max(mx,fr[i+1][j+1]);
         mn=min(mn,on[i-1][j-1]);
        mn=min(mn,tw[i-1][j+1]);
        mn=min(mn,th[i+1][j-1]);
        mn=min(mn,fr[i+1][j+1]);
        ans=min(ans,mx-mn);
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}