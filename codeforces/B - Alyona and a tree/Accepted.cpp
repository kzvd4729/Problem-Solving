/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/02/2018 15:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 639 ms                                          memory_used: 98000 KB                             
*  problem: https://codeforces.com/contest/739/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,aa[N+2],sz[N+2],ent[N+2],ext[N+2],tim,anc[N+2],bit[N+2];
long parent[N+2],sp1[20][N+2],sp2[20][N+2],cost[N+2];
vector<pair<long,long> >adj[N+2];
 void upd(long x,long vl){for( ;x<=N;x+=x&-x)bit[x]+=vl;}
long qry(long x){long ret=0;for( ;x>0;x-=x&-x)ret+=bit[x];return ret;}
 void dfs(long node,long par)
{
  sz[node]=1;parent[node]=par;
  for(auto &x:adj[node])
  {
    dfs(x.first,node);sz[node]+=sz[x.first];
    cost[x.first]=x.second;
    if(sz[x.first]>=sz[adj[node][0].first])swap(x,adj[node][0]);
  }
}
void hld(long node)
{
  ent[node]=++tim;
  for(auto x:adj[node])
  {
    if(x==adj[node][0])anc[x.first]=anc[node];
    else anc[x.first]=x.first;
    hld(x.first);
  }
  ext[node]=tim;
}
void build(void)
{
  memset(sp1,-1,sizeof(sp1));
  for(long i=1;i<=n;i++)
  {
    sp1[0][i]=parent[i];
    sp2[0][i]=cost[i];
  }
  for(long j=1;j<=18;j++)
  {
    for(long i=1;i<=n;i++)
    {
      if(sp1[j-1][i]==-1)continue;
      sp1[j][i]=sp1[j-1][sp1[j-1][i]];
      sp2[j][i]=sp2[j-1][i]+sp2[j-1][sp1[j-1][i]];
    }
  }
}
void _upd(long u,long v)
{
  while(anc[u]!=anc[v])
  {
    upd(ent[anc[u]],1);upd(ent[u]+1,-1);
    u=parent[anc[u]];
  }
  upd(ent[v],1);upd(ent[u]+1,-1);
}
void _cal(long node)
{
  long cs=aa[node];
  for(long j=18;j>=0;j--)
  {
    if(sp1[j][node]==-1)continue;
    if(sp2[j][node]<=cs)
    {
      _upd(parent[node],sp1[j][node]);
      cs-=sp2[j][node];node=sp1[j][node];
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(long i=1;i<=n;i++)
    cin>>aa[i];
  for(long i=2;i<=n;i++)
  {
    long u,w;cin>>u>>w;
    adj[u].push_back({i,w});
  }
  dfs(1,-1);anc[1]=1;hld(1);build();
  for(long i=1;i<=n;i++)_cal(i);
  for(long i=1;i<=n;i++)
    cout<<qry(ent[i])<<" ";
  cout<<endl;
  return 0;
}