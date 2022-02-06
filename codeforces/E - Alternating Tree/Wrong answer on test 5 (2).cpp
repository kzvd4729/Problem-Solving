/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/26/2018 09:49                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 9500 KB                              
*  problem: https://codeforces.com/contest/960/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=2e5;
int n,vl[N+2],sz[N+2],sub[N+2][2];
vector<int>adj[N+2];long ans=0;
void dfs(int node,int par)
{
 sz[node]=1;
 for(int i=0;i<adj[node].size();i++)
 {
  int xx=adj[node][i];if(xx==par)continue;
  dfs(xx,node);sz[node]+=sz[xx];
  sub[node][0]=(sub[node][0]+sub[xx][1])%mod;
  sub[node][1]=(sub[node][1]+sub[xx][0])%mod;
 }
 sub[node][0]=(sub[node][0]+sz[node]*vl[node])%mod;
 sub[node][1]=(sub[node][1]+sz[node]*vl[node]*(-1))%mod;
}
void dds(int node,int par,long pos,long neg)
{
 ans=(ans+pos)%mod;
 for(int i=0;i<adj[node].size();i++)
 {
  int xx=adj[node][i];if(xx==par)continue;
  long ps=pos,ng=neg;
  ps=(neg-sz[xx]*vl[node]*(-1)+(sz[1]-sz[xx])*vl[xx])%mod;
  ng=(pos-sz[xx]*vl[node]+(sz[1]-sz[xx])*vl[xx]*(-1))%mod;
  dds(xx,node,ps,ng);
 }
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>vl[i];
 for(int i=1;i<n;i++)
 {
  int u,v;cin>>u>>v;
  adj[u].push_back(v);
  adj[v].push_back(u);
 }dfs(1,-1);
 dds(1,-1,sub[1][0],sub[1][1]);
 cout<<ans<<endl;
 return 0;
}