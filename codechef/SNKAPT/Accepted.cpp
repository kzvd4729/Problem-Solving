/****************************************************************************************
*  @author: kzvd4729                                         created: 14-07-2019 16:37:12                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.80 sec                                        memory_used: 155.8M                               
*  problem: https://www.codechef.com/JULY19A/problems/SNKAPT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=256;
const long R=1e6;
char mt[N+2][N+2];
long pp[N+2][N+2][82];
long mp[82][N+2][N+2],sr,sn;
const long inf=1e16;
struct edge
{
  long a,b,f,c,d;
};
vector<edge>ed;
vector<long>adj[R+2];
void addEdge(long a,long b,long c,long d)
{
  //cout<<a<<" --> "<<b<<endl;
  edge e;e={a,b,0,c,d};
  adj[a].push_back(ed.size());
  ed.push_back(e);
  e={b,a,0,0,-d};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
long dis[R+2],inq[R+2],mnf[R+2],pth[R+2];
pair<long,long>spfa(long n)
{
  for(long i=0;i<=n;i++)dis[i]=inf;
  queue<long>q;q.push(sr);
  dis[sr]=0,inq[sr]=1,mnf[sr]=inf;
  while(!q.empty())
  {
    long u=q.front();q.pop();inq[u]=0;
    for(auto id:adj[u])
    {
      long v=ed[id].b;
      if(ed[id].c>ed[id].f&&dis[v]>dis[u]+ed[id].d)
      {
        dis[v]=dis[u]+ed[id].d,pth[v]=id;
        mnf[v]=min(mnf[u],ed[id].c-ed[id].f);
        if(!inq[v])q.push(v),inq[v]=1;
      }
    }
  }
  //cout<<"*"<<dis[sn]<<endl;
  if(dis[sn]==inf)return {0,0};
  long v=sn;
  while(v!=sr)
  {
    long id=pth[v];
    ed[id].f+=mnf[sn],ed[id^1].f-=mnf[sn];
    v=ed[id].a;
  }
  return {mnf[sn],dis[sn]*mnf[sn]};
}
pair<long,long>mcmf(long n)
{
  long flow=0,cost=0;
  while(true)
  {
    pair<long,long>p=spfa(n);
    if(!p.first)return {flow,cost};
    flow+=p.first,cost+=p.second;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,z,t;cin>>n>>m>>z>>t;
  for(long i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(long j=1;j<=m;j++)
      mt[i][j]=s[j-1];
  }
  for(long i=1;i<=z;i++)
  {
    long x,y;cin>>x>>y;
    long u,v,w;cin>>u>>v>>w;
    for(long j=u+1;j<=v;j++)
      pp[x][y][j]=max(pp[x][y][j],w);
  }
  long cnt=0;
  for(long tm=0;tm<=t;tm++)
  {
    for(long i=1;i<=n;i++)
    {
      for(long j=1;j<=m;j++)
      {
        if(mt[i][j]!='#')
          addEdge(cnt+1,cnt+2,1,0);
        mp[tm][i][j]=cnt+1;cnt+=2;
      }
    }
  }
  sr=0,sn=cnt+1;//cout<<sn<<endl;
  for(long tm=0;tm<t;tm++)
  {
    for(long i=1;i<=n;i++)
    {
      for(long j=1;j<=m;j++)
      {
        long ent=mp[tm][i][j],ext=ent+1;
                addEdge(ext,mp[tm+1][i][j],1,-pp[i][j][tm+1]);
        if(i+1<=n)
          addEdge(ext,mp[tm+1][i+1][j],1,0);
        if(j+1<=m)
          addEdge(ext,mp[tm+1][i][j+1],1,0);
        if(i-1>=1)
          addEdge(ext,mp[tm+1][i-1][j],1,0);
        if(j-1>=1)
          addEdge(ext,mp[tm+1][i][j-1],1,0);
      }
    }
  }
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=m;j++)
    {
      if(mt[i][j]=='S')
      {
        //cout<<"here"<<endl;
        addEdge(sr,mp[0][i][j],1,0);
      }
      addEdge(mp[t][i][j]+1,sn,1,0);
    }
  }
  //cout<<sn<<endl;
  pair<long,long>p=mcmf(sn);
  cout<<-p.second<<endl;
  //cout<<p.first<<" "<<-p.second<<endl;
  return 0;
}