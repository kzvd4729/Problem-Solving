/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-15 22:25:32                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1316
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2;
const int inf=1e9;
int dis[N+2][N+2],in[N+2],dp[(1<<15)+2][16];
vector<pair<int,int> >adj[N+2];
void spfa(int nd)
{
  memset(in,0,sizeof(in));
  dis[nd][nd]=0;queue<int>q;
  q.push(nd);in[nd]=1;

  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      if(dis[nd][x.first]>dis[nd][u]+x.second)
      {
        dis[nd][x.first]=dis[nd][u]+x.second;
        if(!in[x.first])q.push(x.first),in[x.first]=1;
      }
    }
  }
}
int ss[N+2],s;
int cal(void)
{
  for(int msk=0;msk<(1<<s);msk++)
    for(int i=0;i<s;i++)dp[msk][i]=inf;
  for(int i=0;i<s;i++)
    dp[(1<<i)][i]=dis[0][ss[i]];
  for(int msk=1;msk<(1<<s);msk++)
    for(int i=0;i<s;i++)
      for(int j=0;j<s;j++)
        dp[msk|(1<<j)][j]=min(dp[msk|(1<<j)][j],dp[msk][i]+dis[ss[i]][ss[j]]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m>>s;
    for(int i=0;i<n;i++)adj[i].clear();
    for(int i=0;i<s;i++)cin>>ss[i];
    while(m--)
    {
      int u,v,w;cin>>u>>v>>w;
      adj[u].push_back({v,w});
    }
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        dis[i][j]=inf;
    spfa(0);
    for(int i=0;i<s;i++)
      spfa(ss[i]);
    cout<<"Case "<<++tc<<": ";
    if(dis[0][n-1]==inf){cout<<"Impossible\n";continue;}
    cal();int nd=0,mn=inf;
    for(int i=0;i<(1<<s);i++)
    {
      for(int j=0;j<s;j++)
      {
        if(dp[i][j]==inf||dis[ss[j]][n-1]==inf)continue;
        //cout<<dp[i][j]<<endl;
        int now=__builtin_popcount(i);
        if(now>nd)nd=now,mn=dp[i][j]+dis[ss[j]][n-1];
        else if(nd==now)mn=min(mn,dp[i][j]+dis[ss[j]][n-1]);
      }
    }
    if(nd==0)mn=0;
    cout<<nd<<" "<<mn<<"\n";
  }
  return 0;
}