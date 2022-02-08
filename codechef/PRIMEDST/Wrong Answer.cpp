/****************************************************************************************
*  @author: kzvd4729                                         created: 14-09-2018 18:58:42                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 18.8M                                
*  problem: https://www.codechef.com/problems/PRIMEDST
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int vis[N+2],n,sz[N+2],tot;
int mark[N+2],cnt[N+2];
vector<int>pr,adj[N+2],cl;
long ans=0;
void seive(void)
{
  pr.push_back(2);
  for(int i=4;i<=N;i+=2)vis[i]=1;
  for(int i=3;i<=N;i+=2)
  {
    if(vis[i])continue;pr.push_back(i);
    if(i>sqrt(N+1))continue;
    for(int j=i*i;j<=N;j+=2*i)
      vis[j]=1;
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
void make_dist(int node,int par,int lv)
{
  cnt[lv]++;cl.push_back(node);
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    make_dist(x,node,lv+1);
  }
}
void cal_dist(int node,int par,int lv)
{
  cnt[lv]--;
  int id=lower_bound(pr.begin(),pr.end(),lv)-pr.begin();
  for( ; ;id++)
  {
    int rq=pr[id]-lv;if(rq>=lv)break;
    if(!rq)ans++;
    ans+=cnt[rq]*1LL;
  }
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    cal_dist(x,node,lv+1);
  }
  cnt[lv]++;
}
void centroid(int node,int par)
{
  tot=0;dfs(node,-1);
  int center=find_center(node,-1);
  make_dist(center,-1,0);
  ans+=(cnt[1]*1LL*cnt[1]-1)/2;
  cal_dist(center,-1,0);
  for(auto x:cl)cnt[x]=0;cl.clear();
  return ;
  mark[center]=1;
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    centroid(x,node);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  centroid(1,-1);
  long all=(n*(n-1))/2;
  cout<<setprecision(10)<<fixed<<(ans*1.0)/(all*1.0)<<endl;
  return 0;
}