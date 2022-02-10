/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-19 01:36:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 7760                                       memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-bst-maintenance
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=250000;
int n,sq[N+2],sz[N+2],mark[N+2];long ans;
int tot,dist[N+2][22],anc[N+2],level[N+2],mx;
int lft[N+2],rgt[N+2];
vector<int>adj[N+2];set<int>st;
struct contrubation
{
  int cnt;
  long sm;
  unordered_map<int,pair<int,long> >mp;
}con[N+2];
void insrt(int x)
{
  auto lb=st.lower_bound(x);
  if(lb!=st.end())
  {
    if(!lft[*lb])
    {
      lft[*lb]=x;
      adj[*lb].push_back(x);
      adj[x].push_back(*lb);
    }
  }
  if(lb!=st.begin())
  {
    --lb;
    if(!rgt[*lb])
    {
      rgt[*lb]=x;
      adj[*lb].push_back(x);
      adj[x].push_back(*lb);
    }
  }
  st.insert(x);
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
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>sq[i];insrt(sq[i]);
  }
  centroid(1,0,0);
  for(int i=1;i<=n;i++)
  {
    int x=sq[i];
    int a=anc[x],b=x;ans+=con[x].sm;
    while(a)
    {
      ans+=(con[a].sm-con[a].mp[b].second)+((con[a].cnt-con[a].mp[b].first)*1LL)*dist[x][level[a]];
      b=a;a=anc[a];
    }
    con[x].cnt++;a=anc[x];b=x;
    while(a)
    {
      con[a].cnt++;con[a].sm+=dist[x][level[a]];
      con[a].mp[b].first++;
      con[a].mp[b].second+=(dist[x][level[a]]*1LL);
      b=a;a=anc[a];
    }
    cout<<ans<<"\n";
  }
  return 0;
}