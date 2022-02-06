/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2020 19:57                        
*  solution_verdict: Wrong answer on test 57                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 31500 KB                             
*  problem: https://codeforces.com/contest/543/problem/B
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
#define long long long
using namespace std;
const int N=1e6,R=1e9;
int d[N+2],n,ds1[N+2],ds2[N+2],dt1[N+2],dt2[N+2],ans;
vector<int>adj[N+2];
void bfs(int s)
{
  for(int i=1;i<=n;i++)d[i]=R;
  queue<int>q;q.push(s);d[s]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
      if(d[u]+1<d[x])d[x]=d[u]+1,q.push(x);
  }
}
int l1,l2;
void dfs(int bg,int node)
{
  int df=ds1[node]-ds1[bg];
  int b=min(ds2[bg]+dt2[node],ds2[node]+dt2[bg])+df;
  if(ds1[bg]+df+dt1[node]<=l1&&b<=l2)
    ans=min(ans,ds1[bg]+dt1[node]+b);
  for(auto x:adj[node])
    if(ds1[x]==ds1[node]+1)dfs(bg,x);
}
void dfs2(int bg,int node)
{
  int df=ds2[node]-ds2[bg];
  int b=min(ds1[bg]+dt1[node],ds1[node]+dt1[bg])+df;
  if(ds2[bg]+df+dt2[node]<=l2&&b<=l1)
    ans=min(ans,ds2[bg]+dt2[node]+b);
  for(auto x:adj[node])
    if(ds2[x]==ds2[node]+1)dfs2(bg,x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  int s1,t1,s2,t2;cin>>s1>>t1>>l1>>s2>>t2>>l2;
  bfs(s1);for(int i=1;i<=n;i++)ds1[i]=d[i];
  bfs(t1);for(int i=1;i<=n;i++)dt1[i]=d[i];
  bfs(s2);for(int i=1;i<=n;i++)ds2[i]=d[i];
  bfs(t2);for(int i=1;i<=n;i++)dt2[i]=d[i];
  if(ds1[t1]>l1||ds2[t2]>l2)cout<<-1<<endl,exit(0);
  ans=ds1[t1]+ds2[t2];
  for(int i=1;i<=n;i++)dfs(i,i),dfs2(i,i);cout<<m-ans<<endl;
  return 0;
}