/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/12/2020 17:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 857 ms                                          memory_used: 215000 KB                            
*  problem: https://codeforces.com/contest/757/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>dir[N+2],par[N+2],dom[N+2],topo;
int vis[N+2],lvl[N+2],sp[N+2][20+2];
void dfs(int node)
{
  vis[node]=1;
  for(auto x:dir[node])if(!vis[x])dfs(x);
  topo.push_back(node);
}
int lca(int u,int v)
{
  if(lvl[u]<lvl[v])swap(u,v);
  for(int i=19;i>=0;i--)
  {
    if(sp[u][i]==-1)continue;
    if(lvl[sp[u][i]]>=lvl[v])u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=19;i>=0;i--)
  {
    if(sp[u][i]==-1||sp[u][i]==sp[v][i])continue;
    u=sp[u][i];v=sp[v][i];
  }
  return sp[u][0];
}
void upd(int pr,int ch)
{
  sp[ch][0]=pr;
  for(int i=1;i<20;i++)
  {
    if(sp[ch][i-1]==-1)break;
    sp[ch][i]=sp[sp[ch][i-1]][i-1];
  }
  lvl[ch]=lvl[pr]+1;dom[pr].push_back(ch);
}
void solve(vector<pair<int,int> >ed,int s)//directed graph is in ed
{
  for(auto x:ed)
  {
    dir[x.first].push_back(x.second);
    par[x.second].push_back(x.first);
  }
  dfs(s);reverse(topo.begin(),topo.end());
  memset(sp,-1,sizeof(sp));
  for(int i=1;i<topo.size();i++)
  {
    int x=topo[i];int dm=par[x][0];
    for(int j=1;j<par[x].size();j++)
      dm=lca(dm,par[x][j]);
    upd(dm,x);
  }
}
long d[N+2];int qd[N+2];
const long inf=1e18;vector<pair<int,int> >adj[N+2];
void spfa(int n,int sr)
{
  for(int i=1;i<=n;i++)d[i]=inf,qd[i]=0;
  queue<int>q;q.push(sr);qd[sr]=1,d[sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();qd[u]=0;
    for(auto x:adj[u])
    {
      if(d[u]+x.second<d[x.first])
      {
        d[x.first]=d[u]+x.second;
        if(!qd[x.first])q.push(x.first),qd[x.first]=1;
      }
    }
  }
}
int sub[N+2];
void dfs1(int node)
{
  sub[node]=1;
  for(auto x:dom[node])
  {
    dfs1(x);sub[node]+=sub[x];
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,s;cin>>n>>m>>s;vector<vector<int> >ed;
  while(m--)
  {
    int u,v,w;cin>>u>>v>>w;
    ed.push_back({u,v,w});ed.push_back({v,u,w});
    adj[u].push_back({v,w});adj[v].push_back({u,w});
  }
  spfa(n,s);vector<pair<int,int> >v;
  for(auto x:ed)
  {
    if(d[x[0]]+x[2]!=d[x[1]])continue;
    v.push_back({x[0],x[1]});
  }
  solve(v,s);
  dfs1(s);int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(i!=s)ans=max(ans,sub[i]);
  }
  cout<<ans<<endl;
   return 0;
}