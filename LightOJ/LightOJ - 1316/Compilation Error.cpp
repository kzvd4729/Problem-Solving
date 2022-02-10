/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-05 18:35:42                      
*  solution_verdict: Compilation Error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1316
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e2,inf=1e8;
int ss[N+2],ds[20][N+2],n,s,mx,vs[(1<<16)+2][16];
int dp[(1<<16)+2][16];
vector<pair<int,int> >adj[N+2];
void cal(int a)
{
  for(int i=0;i<n;i++)
    ds[a][i]=inf;
  queue<int>q;q.push(ss[a]);ds[a][ss[a]]=0;
  while(q.size())
  {
    int p=q.front();q.pop();
    for(auto x:adj[p])
    {
      if(ds[a][p]+x.second<ds[a][x.first])
      {
        ds[a][x.first]=ds[a][p]+x.second;
        q.push(x.first);
      }
    }
  }
}
void dfs(int msk,int nd)
{
  if(vs[msk][nd])return ;vs[msk][nd]=1;
  if(ds[nd][n-1]<inf)
  {
    mx=max(mx,__builtin_popcount(msk));
  }
  for(int i=1;i<s;i++)
  {
    if((msk&(1<<i)))continue;
    if(ds[nd][ss[i]]<inf)
      dfs((msk|(1<<i)),i);
  }
}
int dfs2(int msk,int nd)
{
  if(dp[msk][nd]!=-1)return dp[msk][nd];
  if(__builtin_popcount(msk)==mx)
    return ds[nd][n-1];
  int now=inf;
  for(int i=1;i<s;i++)
  {
    if((msk&(1<<i)))continue;
    if(ds[nd][ss[i]]<inf)
      now=min(now,ds[nd][ss[i]]+dfs2((msk|(1<<i)),i));
  }
  return dp[msk][nd]=now;
}
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int m;cin>>n>>m>>s;s++;
    for(int i=1;i<s;i++)cin>>ss[i];
    for(int i=0;i<n;i++)adj[i].clear();
    while(m--)
    {
      int u,v,w;cin>>u>>v>>w;
      adj[u].push_back({v,w});
    }
    for(int i=0;i<s;i++)
      cal(i);
    memset(vs,0,sizeof(vs));
    mx==-1;dfs(0,0);
    cout<<"Case "<<++tc<<": ";
    if(mx==-1)cout<<"Impossible"<<endl;
    else 
    {
      cout<<mx<<" ";
      memset(dp,-1,sizeof(dp));
      cout<<dfs2(0,0)<<endl;
    }
  }
  return 0;
}