/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/24/2019 00:53                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 36500 KB                             
*  problem: https://codeforces.com/contest/1229/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,mod=1e9+7;
long aa[N+2],sp[N+2][18][2];
vector<int>adj[N+2];
void dfs(int n,int p)
{
  sp[n][0][0]=p,sp[n][0][1]=aa[n];
  for(auto x:adj[n])
  {
    if(x==p)continue;
    dfs(x,n);
  }
}
void build(int n)
{
  for(int j=1;j<18;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(sp[i][j-1][0]==-1)continue;
      sp[i][j][0]=sp[sp[i][j-1][0]][j-1][0];
      sp[i][j][1]=__gcd(sp[i][j-1][1],sp[sp[i][j-1][0]][j-1][1]);
    }
  }
}
int main()
{
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
    for(int j=0;j<18;j++)sp[i][j][0]=-1;
  dfs(1,-1);build(n);long ans=0;
  for(int i=1;i<=n;i++)
  {
    long gc=aa[i];int u=i,p=sp[i][0][0];
    int loop=45;
    while(loop--)
    {
      int cnt=1;
      for(int j=17;j>=0;j--)
      {
        if(p==-1||sp[u][j][0]==-1)continue;
        if(sp[p][j][1]==gc)
        {
          cnt+=(1<<j),u=sp[u][j][0];
          p=sp[u][0][0];
        }
      }
      ans=(ans+gc*cnt)%mod;if(p==-1)break;
      gc=__gcd(gc,aa[p]);u=p;p=sp[u][0][0];
    }
  }
  cout<<ans<<endl;
  return 0;
}