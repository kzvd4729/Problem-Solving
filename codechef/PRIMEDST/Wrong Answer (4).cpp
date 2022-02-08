/****************************************************************************************
*  @author: kzvd4729                                         created: 14-09-2018 19:28:51                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 21M                                  
*  problem: https://www.codechef.com/problems/PRIMEDST
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long vis[N+2],n,sz[N+2],tot;
long mark[N+2],cnt[N+2],mx;
vector<long>pr,adj[N+2];
long ans;
void seive(void)
{
  pr.push_back(2);
  for(long i=4;i<=N;i+=2)vis[i]=1;
  for(long i=3;i<=N;i+=2)
  {
    if(vis[i])continue;pr.push_back(i);
    if(i>sqrt(N+1))continue;
    for(long j=i*i;j<=N;j+=2*i)
      vis[j]=1;
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
void make_dist(long node,long par,long lv)
{
  cnt[lv]++;mx=max(mx,lv);
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    make_dist(x,node,lv+1);
  }
}
void cal_dist(long node,long par,long lv)
{
  cnt[lv]--;
  //cout<<ans<<" ";
  long id=lower_bound(pr.begin(),pr.end(),lv)-pr.begin();
  for( ; ;id++)
  {
    long rq=pr[id]-lv;if(rq>=lv)break;
    if(!rq)ans++;
    ans+=cnt[rq]*1LL;
  }
  //cout<<node<<" "<<ans<<endl;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    cal_dist(x,node,lv+1);
  }
  cnt[lv]++;
}
void centroid(long node,long par)
{
  tot=0;dfs(node,-1);
  long center=find_center(node,-1);
  //cout<<center<<endl;
  mx=0;make_dist(center,-1,0);
  ans+=(cnt[1]*1LL*(cnt[1]-1))/2;
  cal_dist(center,-1,0);
  for(int i=0;i<=mx;i++)cnt[i]=0;
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
  for(long i=1;i<n;i++)
  {
    long u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  centroid(1,-1);
  long all=(n*1LL*(n-1))/2;
  //cout<<ans<<endl;
  cout<<setprecision(10)<<fixed<<(ans*1.0)/(all*1.0)<<endl;
  return 0;
}