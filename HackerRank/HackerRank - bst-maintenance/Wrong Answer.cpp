/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-18 21:50:20                      
*  solution_verdict: Wrong Answer                            language: php                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-bst-maintenance
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=250000;
int n,sq[N+2],SZ=1,sz[N+2],mark[N+2];
int tot,dist[N+2][22],anc[N+2],level[N+2];
vector<int>adj[N+2];
struct bst
{
  int lt,rt,vl;
}arr[N+2];
struct contrubation
{
  int cnt,sm;
  map<int,pair<int,int> >mp;
}con[N+2];
void insrt(int node,int x)
{
  if(!arr[node].vl)
  {
    arr[node].vl=x;
    return ;
  }
  if(x<arr[node].vl)
  {
    if(!arr[node].lt)
    {
      arr[node].lt=++SZ;
      adj[arr[node].vl].push_back(x);
      adj[x].push_back(arr[node].vl);
    }
    insrt(arr[node].lt,x);
  }
  else
  {
    if(!arr[node].rt)
    {
      arr[node].rt=++SZ;
      adj[arr[node].vl].push_back(x);
      adj[x].push_back(arr[node].vl);
    }
    insrt(arr[node].rt,x);
  }
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
void cal_dist(int node,int par,int lv,int ds)
{
  dist[node][lv]=ds;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    cal_dist(x,node,lv,ds+1);
  }
}
void centroid(int node,int par,int lv)
{
  tot=0;dfs(node,-1);
  int center=find_center(node,-1);
  cal_dist(center,-1,lv,0);mark[center]=1;
  anc[center]=par;level[center]=lv;
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    centroid(x,center,lv+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(int i=1;i<=n;i++)cin>>sq[i],insrt(1,sq[i]);
  centroid(1,0,0);
  for(int i=1;i<=n;i++)
  {
    int x=sq[i];
    int a=anc[x];long ans=0;
    while(a)
    {
      ans+=(con[a].sm-con[a].mp[x].second)+(con[a].cnt-con[a].mp[x].first+1)*dist[x][level[a]];
      a=anc[a];
    }
    a=anc[x];
    while(a)
    {
      con[a].cnt++;
      con[a].sm+=dist[x][level[a]];
      con[a].mp[x].first++;
      con[a].mp[x].second+=dist[x][level[a]];
      a=anc[a];
    }
    cout<<ans<<endl;
  }
  return 0;
}