/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2018 23:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 3010 ms                                         memory_used: 26800 KB                             
*  problem: https://codeforces.com/contest/990/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,sz[N+2],tot,cnt[N+2],vis[N+2];
int mark[N+2],arr[N+2],tmp[N+2];
vector<int>adj[N+2],dvv[N+2],ccl,vsl;
unordered_set<int>mcl;
long ans[N+2];
void divisors(void)
{
  for(int i=1;i<=N;i++)
    for(int j=i;j<=N;j+=i)
      dvv[j].push_back(i);
  int mx=0;
}
void dfs(int node,int par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    dfs(x,node);sz[node]+=sz[x];
  }
}
int find_center(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    if(sz[x]>tot/2)return find_center(x,node);
  }
  return node;
}
void cal_gcd(int node,int par,int gcd)
{
  cnt[gcd]++;if(cnt[gcd]==1)mcl.insert(gcd);
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    cal_gcd(x,node,__gcd(gcd,arr[x]));
  }
}
void ers_gcd(int node,int par,int gcd)
{
  cnt[gcd]--;if(cnt[gcd]==0)mcl.erase(gcd);
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    ers_gcd(x,node,__gcd(gcd,arr[x]));
  }
}
void cal_ans(int node,int par,int gcd)
{
  for(auto x:mcl)
    ans[__gcd(gcd,x)]+=cnt[x];
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    cal_ans(x,node,__gcd(gcd,arr[x]));
  }
}
void centroid(int node,int par)
{
  tot=0;dfs(node,-1);
  int center=find_center(node,-1);
  mark[center]=1;
  cal_gcd(center,-1,arr[center]);
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    ers_gcd(x,-1,__gcd(arr[center],arr[x]));
    cal_ans(x,-1,__gcd(arr[center],arr[x]));
  }
  cnt[arr[center]]=0;
  mcl.clear();
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    centroid(x,node);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  mcl.max_load_factor(0.25);mcl.reserve(512);
  cin>>n;for(int i=1;i<=n;i++)cin>>arr[i],ans[arr[i]]++;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  centroid(1,-1);
  cout<<endl;
  for(int i=1;i<=N;i++)
    if(ans[i])cout<<i<<" "<<ans[i]<<"\n";
  return 0;
}