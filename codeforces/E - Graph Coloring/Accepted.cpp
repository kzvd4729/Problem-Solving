/****************************************************************************************
*  @author: kzvd4729                                         created: May/23/2020 17:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 217 ms                                          memory_used: 99300 KB                             
*  problem: https://codeforces.com/contest/1354/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=5e3;
int n,m,a,b,c,cl[N+2],cnt[N+2];
vector<int>adj[N+2];
vector<vector<int> >v;
void dfs(int node,int f)
{
  if(cl[node]==-1)cl[node]=f;
  else if(cl[node]!=f)cout<<"NO\n",exit(0);
  else if(cl[node]!=-1)return ;
  cnt[f]++;
  for(auto x:adj[node])dfs(x,f^1);
}
int dp[N+2][N+2];
bool ok(int i,int b)
{
  if(i==v.size())return dp[i][b]=(b==0);
  if(dp[i][b]!=-1)return dp[i][b];
  return dp[i][b]=ok(i+1,b-v[i][0])|ok(i+1,b-v[i][1]);
}
int ans[N+2];
void color(int node,int f)
{
  if(ans[node])return ;
  if(f==0)ans[node]=2;
  else if(a)ans[node]=1,a--;
  else ans[node]=3;
   for(auto x:adj[node])color(x,f^1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>a>>b>>c;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  memset(cl,-1,sizeof cl);
  for(int i=1;i<=n;i++)
  {
    if(cl[i]!=-1)continue;
    cnt[0]=0,cnt[1]=0;dfs(i,0);
    v.push_back({cnt[0],cnt[1],i});
  }
  //for(auto x:v)cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
  memset(dp,-1,sizeof dp);
  if(ok(0,b)==0)cout<<"NO\n",exit(0);
  for(int i=0;i<v.size();i++)
  {
    if(dp[i+1][b-v[i][0]])color(v[i][2],0),b-=v[i][0];
    else color(v[i][2],1),b-=v[i][1];
  }
  cout<<"YES\n";
  for(int i=1;i<=n;i++)cout<<ans[i];
  cout<<"\n";
  return 0;
}