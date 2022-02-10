/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-18 22:28:13                      
*  solution_verdict: Terminated due to timeout               language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-bst-maintenance
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=250000;
long n,sq[N+2],SZ=1,sz[N+2],mark[N+2],ans;
long tot,dist[N+2][22],anc[N+2],level[N+2],eql[N+2];
vector<long>adj[N+2];set<long>st;
struct bst
{
  long lt,rt,vl;
}arr[N+2];
struct contrubation
{
  long cnt,sm;
  map<long,pair<long,long> >mp;
}con[N+2];
void insrt(long node,long x)
{
  if(!arr[node].vl)
  {
    arr[node].vl=x;eql[x]=node;
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
void dfs(long node,long par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    dfs(x,node);sz[node]+=sz[x];
  }
}
long find_center(long node,long par)
{
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    if(sz[x]>tot/2)return find_center(x,node);
  }
  return node;
}
void cal_dist(long node,long par,long lv,long ds)
{
  dist[node][lv]=ds;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    cal_dist(x,node,lv,ds+1);
  }
}
void centroid(long node,long par,long lv)
{
  tot=0;dfs(node,-1);
  long center=find_center(node,-1);
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
  cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>sq[i];
    insrt(1,sq[i]);
  }
  centroid(1,0,0);
  for(long i=1;i<=n;i++)
  {
    long x=sq[i];
    long a=anc[x],b=x;ans+=con[x].sm;
    while(a)
    {
      ans+=(con[a].sm-con[a].mp[b].second)+(con[a].cnt-con[a].mp[b].first)*dist[x][level[a]];
      b=a;a=anc[a];
    }
    con[x].cnt++;a=anc[x];b=x;
    while(a)
    {
      con[a].cnt++;con[a].sm+=dist[x][level[a]];
      con[a].mp[b].first++;
      con[a].mp[b].second+=dist[x][level[a]];
      b=a;a=anc[a];
    }
    cout<<ans<<endl;
  }
  return 0;
}