/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/29/2019 19:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1228/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,mod=1e9+7;
int vis[N+2][N+2];
void no()
{
  cout<<0<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    for(int j=1;j<=x;j++)
      vis[i][j]=1;
    vis[i][x+1]=2;
  }
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    for(int j=1;j<=x;j++)
    {
      if(vis[j][i]==2)no();
      vis[j][i]=1;
    }
    if(vis[x+1][i]==1)no();
    vis[x+1][i]=2;
  }
  int cnt=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(!vis[i][j])cnt++;
  int ans=1;
  for(int i=1;i<=cnt;i++)
    ans=(ans+ans)%mod;
  cout<<ans<<endl;
  return 0;
}