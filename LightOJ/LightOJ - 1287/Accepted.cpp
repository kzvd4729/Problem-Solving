/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-24 22:13:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1295                                       memory_used (MB): 13.1                            
*  problem: https://vjudge.net/problem/LightOJ-1287
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=15,inf=1e9;
int n,dp1[(1<<15)+2][15+2],dp2[(1<<15)+2][15+2];
double dp3[(1<<15)+2][15+2];
vector<int>adj[N+2],cost[N+2];
bool isReachable(int msk,int l)
{
  if(msk==(1<<n)-1)return 1;
  if(dp1[msk][l]!=-1)return dp1[msk][l];
  bool ret=0;
  for(auto x:adj[l])
  {
    if(!(msk&(1<<x)))
      ret|=isReachable(msk|(1<<x),x);
  }
  return dp1[msk][l]=ret;
}
int rm[(1<<15)+2][15+2];
double dfs(int msk,int l)
{
  int op=__builtin_popcount(rm[msk][l])+1;
  if(op==1)return 0;
  if(dp2[msk][l]!=-1)return dp3[msk][l];
  double p=1.0/(op*1.0);

  double ret=p*5.0;
  for(int i=0;i<adj[l].size();i++)
  {
    int x=adj[l][i];
    if(rm[msk][l]&(1<<x))ret+=p*cost[l][i]+p*dfs(msk|(1<<x),x);
  }
  dp2[msk][l]=1;
  return dp3[msk][l]=ret/(1.0-p);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t,tc=0;cin>>t;
  while(t--)
  {
    int m;cin>>n>>m;
    for(int i=0;i<n;i++)adj[i].clear(),cost[i].clear();
    for(int i=0;i<m;i++)
    {
      int u,v,w;cin>>u>>v>>w;
      adj[u].push_back(v);adj[v].push_back(u);
      cost[u].push_back(w);cost[v].push_back(w);
    }
    for(int i=0;i<(1<<n);i++)
    {
      for(int j=0;j<n;j++)
        dp1[i][j]=-1,dp2[i][j]=-1;
    }
    for(int msk=0;msk<(1<<n);msk++)
    {
      for(int l=0;l<n;l++)
      {
        if(!(msk&(1<<l)))continue;int ad=0;
        for(auto x:adj[l])
        {
          if(!(msk&(1<<x)))
            ad|=(isReachable(msk|(1<<x),x)<<x);
        }
        rm[msk][l]=ad;
        //cout<<msk<<" "<<l<<" "<<ad<<endl;
      }
    }
    cout<<"Case "<<++tc<<": "<<setprecision(6)<<fixed<<dfs(1,0)<<"\n";
  }
  return 0;
}