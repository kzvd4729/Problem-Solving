/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/21/2020 22:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 43800 KB                             
*  problem: https://codeforces.com/contest/512/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e7;
 int isPrime[N+2];vector<int>prime;
void seive(int n)
{
  prime.push_back(2);isPrime[1]=1;
  for(int i=4;i<=n;i+=2)isPrime[i]=1;
  int sq=sqrt(n+1);
  for(int i=3;i<=n;i+=2)
  {
    if(isPrime[i])continue;prime.push_back(i);
    if(i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)
      isPrime[j]=1;
  }
}
//.............................................
struct edge
{
  int a,b,f,c;
};
int sr,sn;//sr=0,sn=last node+1;
vector<edge>ed;
vector<int>adj[N+2];
void clear(void)
{
  ed.clear();
  for(int i=0;i<=sn;i++)
    adj[i].clear();
}
void addEdge(int a,int b,int c)
{
  //cout<<a<<" "<<b<<" --> "<<c<<endl;
  edge e;e={a,b,0,c};
  adj[a].push_back(ed.size());
  ed.push_back(e);e={b,a,0,0};
  //e={b,a,0,c};//for bidirectional
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
//finding all possible path. normal bfs
int dis[N+2],pt[N+2];
bool bfs(void)
{
  for(int i=0;i<=sn;i++)dis[i]=inf;
  queue<int>q;q.push(sr);dis[sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      int v=ed[x].b;
      if(dis[v]==inf&&ed[x].f<ed[x].c)
        dis[v]=dis[u]+1,q.push(v);
    }
  }
  return dis[sn]!=inf;
}
int dfs(int u,int flow)
{
  if(!flow||u==sn)return flow;
  //if there was not possible before, it is not possible now.
  for( ;pt[u]<adj[u].size();pt[u]++)
  {
    int id=adj[u][pt[u]];int v=ed[id].b;
    if(dis[v]!=dis[u]+1)continue;
    if(int pushed=dfs(v,min(flow,ed[id].c-ed[id].f)))
    {
      ed[id].f+=pushed;ed[id^1].f-=pushed;
      return pushed;
    }
  }
  return 0;
}
int dinic(void)
{
  int flow=0;
  while(bfs())
  {
    for(int i=0;i<=sn;i++)pt[i]=0;
    while(int pushed=dfs(sr,inf))
      flow+=pushed;
  }
  return flow;
}
int aa[N+2],vis[N+2];vector<int>ad[N+2],cir;
void dfs(int node)
{
  vis[node]=1;cir.push_back(node);
  for(auto x:ad[node])
    if(!vis[x])dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive(100000);int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   sr=0,sn=n+1;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]%2==0)addEdge(sr,i,2);
    else addEdge(i,sn,2);
  }
  for(int i=1;i<=n;i++)
  {
    if(aa[i]%2)continue;
    for(int j=1;j<=n;j++)
      if(aa[j]%2&&!isPrime[aa[i]+aa[j]])addEdge(i,j,1);
  }
  if(dinic()!=n)cout<<"Impossible\n",exit(0);
  for(auto x:ed)
  {
    if(x.f!=1)continue;
    ad[x.a].push_back(x.b);
    ad[x.b].push_back(x.a);
    //cout<<x.a<<" "<<x.b<<endl;
  }
  vector<vector<int> >ans;memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    cir.clear();dfs(i);ans.push_back(cir);
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
  {
    cout<<x.size();
    for(auto z:x)cout<<" "<<z;
    cout<<endl;
  }
   return 0;
}