/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-13 18:23:23                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1330
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int aa[N+2],bb[N+2],sr,sn,dis[N+2],pt[N+2],vis[N+2],pth[N+2];
map<pair<int,int>,pair<int,int> >mp;
map<pair<int,int>,int>ab;
int mt[52][52];

const int inf=1e9;
struct edge
{
  int a,b,f,c;
};
vector<edge>ed;
vector<int>adj[N+2];
void addEdge(int a,int b,int c)
{
  edge e;e={a,b,0,c}; ab[{a,b}]=ed.size();
  adj[a].push_back(ed.size());
  ed.push_back(e);

  e={b,a,0,0};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
bool bfs(int n)
{
  for(int i=0;i<=n;i++)dis[i]=inf;
  queue<int>q;q.push(sr);dis[sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      int id=adj[u][i];int v=ed[id].b;
      if((dis[v]==inf)&&(ed[id].c-ed[id].f))
        dis[v]=dis[u]+1,q.push(v);
    }
  }
  return dis[sn]!=inf;
}
int dfs(int u,int flow)
{
  if(!flow||u==sn)return flow;
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
int dinic(int n)
{
  int flow=0;
  while(bfs(n))
  {
    for(int i=0;i<=n;i++)pt[i]=0;
    while(int pushed=dfs(sr,inf))
      flow+=pushed;
  }
  return flow;
}
vector<int>clr;
bool aug(int u)
{
  if(u==sn)return true;
  vis[u]=1;clr.push_back(u);
  for(int i=0;i<adj[u].size();i++)
  {
    int id=adj[u][i];int v=ed[id].b;
    if(vis[v]||ed[id].f>=ed[id].c)continue;
    pth[v]=id;if(aug(v))return true;
  }
  return false;
}
bool ck(int n,int nd)
{
  pth[nd]=ab[{sr,nd}];
  if(aug(nd))
  {
    int u=sn;
    while(u!=sr)
    {
      int id=pth[u];
      ed[id].f++;ed[id^1].f--;
      u=ed[id].a;
    }
    //memset(pth,0,sizeof(pth));
    for(int i=0;i<clr.size();i++)
      vis[clr[i]]=0;
    clr.clear();
    return true;
  }
  else
  {
    for(int i=0;i<clr.size();i++)
      vis[clr[i]]=0;
    clr.clear();
    return false;
  }
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;int s1=0,s2=0;
    for(int i=1;i<=n;i++)
      cin>>aa[i],s1+=aa[i];
    for(int i=1;i<=m;i++)
      cin>>bb[i],s2+=bb[i];
    int node=n;mp.clear();ab.clear();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        addEdge(node+1,node+2,1);
        mp[{i,j}]={node+1,node+2};
        node+=2;
      }
    }
    sr=0;
    for(int i=1;i<=n;i++)
    {
      addEdge(sr,i,aa[i]);
      for(int j=1;j<=m;j++)
      {
        addEdge(i,mp[{i,j}].first,1);
      }
    }
    sn=node+m+1;
    for(int j=1;j<=m;j++)
    {
      addEdge(node+j,sn,bb[j]);
      for(int i=1;i<=n;i++)
      {
        addEdge(mp[{i,j}].second,node+j,1);
      }
    }
    cout<<"Case "<<++tc<<":";
    int flow=dinic(sn);
    if(flow!=s1||flow!=s2)cout<<" impossible"<<"\n";
    else
    {
      cout<<"\n";vis[sr]=1;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          mt[i][j]=ed[ab[mp[{i,j}]]].f;
          if(!mt[i][j])
          {
            ed[ab[mp[{i,j}]]].c=0;
            continue;
          }
          int id=ab[{sr,i}];ed[id].f--;ed[id^1].f++;
          id=ab[{i,mp[{i,j}].first}];ed[id].f--;ed[id^1].f++;
          id=ab[{node+j,sn}];ed[id].f--;ed[id^1].f++;
          id=ab[{mp[{i,j}].second,node+j}];ed[id].f--;ed[id^1].f++;

          if(ck(sn,i))mt[i][j]=0;

          if(mt[i][j])
          {
            id=ab[{sr,i}];ed[id].f++;ed[id^1].f--;
            id=ab[{i,mp[{i,j}].first}];ed[id].f++;ed[id^1].f--;
            id=ab[{node+j,sn}];ed[id].f++;ed[id^1].f--;
            id=ab[{mp[{i,j}].second,node+j}];ed[id].f++;ed[id^1].f--;
          }
        }
      }

      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
          cout<<mt[i][j];
        cout<<"\n";
      }
    }

    for(int i=0;i<=sn;i++)
      adj[i].clear();
    ed.clear();
  }
  return 0;
}