/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2019 11:10                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 10300 KB                             
*  problem: https://codeforces.com/contest/1101/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,sz[N+2],tot,cnt[N+2],vis[N+2];
int mark[N+2],arr[N+2],tmp[N+2],mx[N+2],ans;
vector<int>adj[N+2],dvv[N+2],ccl,vsl;
unordered_set<int>mcl;
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
void add(int node,int par,int gc,int hg)
{
  mx[gc]=max(mx[gc],hg);mcl.insert(gc);
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    add(x,node,__gcd(gc,arr[x]),hg+1);
  }
}
void cal(int node,int par,int gc,int hg)
{
  for(int x=1;x<=100;x++)
    if(__gcd(gc,x)>1)
      ans=max(ans,hg+mx[x]);
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    add(x,node,__gcd(gc,arr[x]),hg+1);
  }
}
void centroid(int node,int par)
{
  tot=0;dfs(node,-1);
  int center=find_center(node,-1);
  mark[center]=1;
   if(arr[center]>1)ans=max(ans,1);
  mx[arr[center]]=1;mcl.insert(arr[center]);
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    cal(x,center,arr[x],1);;
    add(x,center,__gcd(arr[x],arr[center]),2);
  }
  for(auto x:mcl)mx[x]=0;mcl.clear();
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
  cin>>n;for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  centroid(1,-1);cout<<ans<<endl;
  return 0;
}