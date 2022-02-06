/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 17:21                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 72400 KB                             
*  problem: https://codeforces.com/contest/1184/problem/B2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int dis[N+2][N+2],slc[N+2],sat[N+2],sfl[N+2];
int blc[N+2],bdf[N+2];
/******************* Max Flow Min Cut *******************/
const int Inf=1e9;
struct Edge
{
  int a,b,f,c;
};
vector<Edge>Ed;
vector<int>FlowAdj[N+2];
void Flow_Add_Edge(int a,int b,int c)
{
  Edge e;e={a,b,0,c};
  FlowAdj[a].push_back(Ed.size());
  Ed.push_back(e);e={b,a,0,0};
  //e={b,a,0,c}//Bidirectional
  FlowAdj[b].push_back(Ed.size());
  Ed.push_back(e);
}
int FlowDis[N+2],Sr,Sn,Pt[N+2];
bool FlowBFS(int n)
{
  for(int i=0;i<=n;i++)FlowDis[i]=Inf;
  queue<int>q;q.push(Sr);FlowDis[Sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(int i=0;i<FlowAdj[u].size();i++)
    {
      int x=FlowAdj[u][i];int v=Ed[x].b;
      if(FlowDis[v]==Inf&&Ed[x].f<Ed[x].c)
        FlowDis[v]=FlowDis[u]+1,q.push(v);
    }
  }
  return FlowDis[Sn]!=Inf;
}
int FlowDFS(int node,int flow)
{
  if(!flow||node==Sn)return flow;
  for( ;Pt[node]<FlowAdj[node].size();Pt[node]++)
  {
    int id=FlowAdj[node][Pt[node]];int v=Ed[id].b;
    if(FlowDis[v]!=FlowDis[node]+1)continue;
    if(int pushed=FlowDFS(v,min(flow,Ed[id].c-Ed[id].f)))
    {
      Ed[id].f+=pushed;Ed[id^1].f-=pushed;
      return pushed;
    }
  }
  return 0;
}
int Dinic(int n)
{
  int flow=0;
  //cout<<Sr<<" -- "<<Sn<<endl;
  while(FlowBFS(n))
  {
    memset(Pt,0,sizeof(Pt));
    while(int pushed=FlowDFS(Sr,Inf))
      flow+=pushed;
  }
  return flow;
}
///////////////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      dis[i][j]=1e9;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    dis[u][v]=1;dis[v][u]=1;
  }
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
  int s,b,k,h;cin>>s>>b>>k>>h;
  for(int i=1;i<=s;i++)
    cin>>slc[i]>>sat[i]>>sfl[i];
  for(int i=1;i<=b;i++)
    cin>>blc[i]>>bdf[i];
  Sr=0,Sn=s+b+1;
  for(int i=1;i<=s;i++)
  {
    for(int j=1;j<=b;j++)
    {
      if(dis[slc[i]][blc[j]]<=sfl[i]&&sat[i]>=bdf[j]);
        Flow_Add_Edge(i,s+j,1);
    }
  }
  for(int i=1;i<=s;i++)Flow_Add_Edge(Sr,i,1);
  for(int j=1;j<=b;j++)Flow_Add_Edge(s+j,Sn,1);
  long one=(Dinic(Sn)*1LL)*(k*1LL);
  long two=(s*1LL)*(h*1LL);
  //cout<<one<<endl;
  cout<<min(one,two)<<endl;
  return 0;
}