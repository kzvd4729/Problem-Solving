/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2019 15:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 576 ms                                          memory_used: 33200 KB                             
*  problem: https://codeforces.com/contest/599/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int ad[20],n;
vector<pair<int,int> >lc[20];
vector<int>sub[N+2];
long dp[14][14][(1<<13)+2][2];
bool chklc(int node,int msk)
{
  for(auto x:lc[node])
  {
    int ms=0;ms|=(1<<x.first);
    ms|=(1<<x.second);
    if((ms&msk)!=ms)return false;
  }
  return true;
}
bool chked(int node,int par,int msk)
{
  int ch=ad[node];
  if((ch&(1<<par)))ch^=(1<<par);
  if((ch&msk)!=ch)return false;
  return true;
}
bool cklc(int node,int msk)
{
  for(auto x:lc[node])
  {
    int ms=0;ms|=(1<<x.first);
    ms|=(1<<x.second);
    if((ms&msk)==ms)return false;
  }
  return true;
}
bool cked(int node,int msk)
{
  int ch=ad[node]&msk;
  if(__builtin_popcount(ch)>1)return false;
  return true;
}
long dfs(int node,int par,int msk,int f)
{
  if(!f)
  {
    if(!chklc(node,msk))return 0;
    if(!chked(node,par,msk))return 0;
  }
  msk^=(1<<node);if(!msk)return 1;
  if(dp[node][par][msk][f]!=-1)return dp[node][par][msk][f];
  int sn=31-__builtin_clz(msk);sn=(1<<sn);
  long now=0;
  for(auto x:sub[msk])
  {
    if(!(x&sn))continue;
    if(!cked(node,x)||!cklc(node,x))continue;
    int ch=(ad[node]&x);long add=0;
    if(__builtin_popcount(ch))
    {
      int dg=31-__builtin_clz(ch);
      add=dfs(dg,node,x,0);
    }
    else
    {
      for(int i=0;i<n;i++)
        if((x&(1<<i)))
          add+=dfs(i,node,x,0);
    }
    now+=add*dfs(node,par,((msk^x)|(1<<node)),1);
  }
  return dp[node][par][msk][f]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;u--,v--;
    ad[u]|=(1<<v);ad[v]|=(1<<u);
  }
  for(int i=1;i<=k;i++)
  {
    int a,b,c;cin>>a>>b>>c;a--,b--,c--;
    lc[c].push_back({a,b});
  }
  for(int i=1;i<(1<<n);i++)
    for(int j=1;j<=i;j++)
      if((i&j)==j)
        sub[i].push_back(j);
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,n,(1<<n)-1,0)<<endl;
  return 0;
}