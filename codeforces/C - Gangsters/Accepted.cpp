/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/17/2019 19:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 3369 ms                                         memory_used: 22500 KB                             
*  problem: https://codeforces.com/gym/101059/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
int lc[N+2],n,m,k,p,dis[11][N+1];
int db[N+2];
bitset<N+2>vis[(1<<10)+2];bool mark[N+2];
vector<int>adj[N+2];
void bfs(int id,int sr)
{
  for(int i=1;i<=n;i++)
    dis[id][i]=inf;
  dis[id][sr]=0;queue<int>q;q.push(sr);
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      if(dis[id][x]>dis[id][u]+1)
      {
        dis[id][x]=dis[id][u]+1;
        q.push(x);
      }
    }
  }
}
void dfs(int id,int node)
{
  mark[node]=1;
  for(auto x:adj[node])
  {
    if(vis[id][x]||mark[x])continue;
    dfs(id,x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>p>>k;
  for(int i=1;i<=p;i++)
    cin>>lc[i];
  long ans=0;
  for(int i=1;i<=p;i++)
  {
    cin>>db[i];ans+=(db[i]*1LL);
  }
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=p;i++)bfs(i,lc[i]);
  int srt,fin;cin>>srt>>fin;
   /*for(int i=1;i<=p;i++)
    dis[i][srt]=inf,dis[i][fin]=inf;*/
   for(int msk=1;msk<(1<<p);msk++)
  {
    long now=0;
    for(int i=0;i<p;i++)
    {
      if(!(msk&(1<<i)))now+=(db[i+1]*1LL);
    }
    int id=32-__builtin_clz(msk);
    int ms=msk^(1<<(id-1));
    for(int i=1;i<=n;i++)
    {
      vis[msk][i]=vis[ms][i];
      if(dis[id][i]<=k)
        vis[msk][i]=1;
    }
    //if(vis[msk][srt])continue;
    memset(mark,0,sizeof(mark));
    dfs(msk,srt);if(mark[fin])ans=min(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}