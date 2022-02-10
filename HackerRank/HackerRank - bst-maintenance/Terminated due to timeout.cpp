/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-18 23:50:12                      
*  solution_verdict: Terminated due to timeout               language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-bst-maintenance
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=250000;
long n,sq[N+2],sz[N+2],mark[N+2],ans;
long tot,dist[N+2][22],anc[N+2],level[N+2],mx;
vector<long>adj[N+2];set<long>st;
struct bst
{
  long lt,rt,vl;
}arr[N+2];
struct contrubation
{
  long cnt,sm;
  unordered_map<long,pair<long,long> >mp;
}con[N+2];
void insrt(long x)
{
  if(x>mx)
  {
    if(mx)
    {
      adj[mx].push_back(x);adj[x].push_back(mx);
      arr[mx].rt=x;
    }
    mx=x;st.insert(x);
    return ;
  }
  int nd=*st.upper_bound(x);
  while(true)
  {
    if(x<nd)
    {
      if(!arr[nd].lt)
      {
        adj[nd].push_back(x);adj[x].push_back(nd);
        arr[nd].lt=x;st.insert(x);return ;
      }
      else nd=arr[nd].lt;
    }
    else
    {
      if(!arr[nd].rt)
      {
        adj[nd].push_back(x);adj[x].push_back(nd);
        arr[nd].rt=x;st.insert(x);return ;
      }
      else nd=arr[nd].rt;
    }
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
    insrt(sq[i]);
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
    cout<<ans<<"\n";
  }
  return 0;
}