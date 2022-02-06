/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/24/2019 01:21                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1229/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,mod=1e9+7;
long aa[N+2],sp[N+2][19][2];
vector<int>adj[N+2];
void dfs(int n,int p)
{
  sp[n][0][0]=n,sp[n][0][1]=aa[n];
  sp[n][1][0]=p;if(p!=-1)sp[n][1][1]=__gcd(aa[n],aa[p]);
  for(auto x:adj[n])
  {
    if(x==p)continue;
    dfs(x,n);
  }
}
void build(int n)
{
  for(int j=2;j<19;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[i][j-1][0]==-1)continue;
      int u=sp[sp[i][j-1][0]][0][0];if(u==-1)continue;
      sp[i][j][0]=sp[u][j-1][0];
      sp[i][j][1]=__gcd(sp[i][j-1][1],sp[u][j-1][1]);
    }
  }
}
int main()
{
  dont't compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
    for(int j=0;j<19;j++)sp[i][j][0]=-1;
  dfs(1,-1);build(n);long ans=0;
  for(int i=5;i<=5;i++)
  {
    long gc=aa[i],tt=0;
    while(true)
    {
      int cnt=0,u=i;long now=0;
      for(int j=18;j>=0;j--)
      {
        if(u==-1||sp[u][j][0]==-1)continue;
        if(__gcd(now,sp[u][j][1])==gc)
        {
          cnt+=(1<<j),u=sp[u][j][0];
          u=sp[u][1][0];now=__gcd(now,sp[u][j][1]);
        }
      }
      cnt-=tt;tt=cnt;
      ans=(ans+gc*cnt)%mod;if(u==-1)break;
      gc=__gcd(gc,aa[u]);
    }
  }
  cout<<ans<<endl;
  return 0;
}