/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 18:48                        
*  solution_verdict: Runtime error on test 52                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 144300 KB                            
*  problem: https://codeforces.com/contest/1184/problem/B2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e3;
long dis[N+2][N+2],slc[N+2],sat[N+2],sfl[N+2];
long blc[N+2],bdf[N+2];
/******************* Max Flow Min Cut *******************/
const long Inf=1e15;
struct Edge
{
  long a,b,f,c;
};
vector<Edge>Ed;
vector<long>FlowAdj[N+2];
void Flow_Add_Edge(long a,long b,long c)
{
  //cout<<a<<" --> "<<b<<endl;
  if(a<0||a>N||b<0||b>N)assert(0);
  Edge e;e={a,b,0,c};
  FlowAdj[a].push_back((long)Ed.size());
  Ed.push_back(e);e={b,a,0,0};
  //e={b,a,0,c};//Bidirectional
  FlowAdj[b].push_back((long)Ed.size());
  Ed.push_back(e);
}
long FlowDis[N+2],Sr,Sn,Pt[N+2];
bool FlowBFS(long n)
{
  for(long i=0;i<=n;i++)FlowDis[i]=Inf;
  queue<long>q;q.push(Sr);FlowDis[Sr]=0;
  while(q.size())
  {
    long u=q.front();q.pop();
    for(long i=0;i<FlowAdj[u].size();i++)
    {
      long x=FlowAdj[u][i];long v=Ed[x].b;
      if(FlowDis[v]==Inf&&Ed[x].f<Ed[x].c)
        FlowDis[v]=FlowDis[u]+1,q.push(v);
    }
  }
  return FlowDis[Sn]!=Inf;
}
long FlowDFS(long node,long flow)
{
  if(!flow||node==Sn)return flow;
  for( ;Pt[node]<FlowAdj[node].size();Pt[node]++)
  {
    long id=FlowAdj[node][Pt[node]];long v=Ed[id].b;
    if(FlowDis[v]!=FlowDis[node]+1)continue;
    if(long pushed=FlowDFS(v,min(flow,Ed[id].c-Ed[id].f)))
    {
      Ed[id].f+=pushed;Ed[id^1].f-=pushed;
      return pushed;
    }
  }
  return 0;
}
long Dinic(long n)
{
  long flow=0;
  //cout<<Sr<<" -- "<<Sn<<endl;
  while(FlowBFS(n))
  {
    memset(Pt,0,sizeof(Pt));
    while(long pushed=FlowDFS(Sr,Inf))
      flow+=pushed;
  }
  return flow;
}
///////////////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
  for(long i=1;i<=n;i++)
    for(long j=1;j<=n;j++)
      dis[i][j]=1e15+1;
  for(long i=1;i<=m;i++)
  {
    long u,v;cin>>u>>v;
    dis[u][v]=1;dis[v][u]=1;
  }
  for(int i=1;i<=n;i++)
    dis[i][i]=0;
  for(long k=1;k<=n;k++)
    for(long i=1;i<=n;i++)
      for(long j=1;j<=n;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
  long s,b,k,h;cin>>s>>b>>k>>h;
  for(long i=1;i<=s;i++)
    cin>>slc[i]>>sat[i]>>sfl[i];
  for(long i=1;i<=b;i++)
    cin>>blc[i]>>bdf[i];
  Sr=0,Sn=s+b+1;
  for(long i=1;i<=s;i++)
  {
    for(long j=1;j<=b;j++)
    {
      if((dis[slc[i]][blc[j]]<=sfl[i])&&(sat[i]>=bdf[j]))
      {
        //cout<<sat[i]<<" -- "<<bdf[j]<<endl;
        //cout<<(sat[i]>=bdf[j])<<endl;
        Flow_Add_Edge(i,s+j,1);
      }
    }
  }
  for(long i=1;i<=s;i++)Flow_Add_Edge(Sr,i,1);
  for(long j=1;j<=b;j++)Flow_Add_Edge(s+j,Sn,1);
  long one=(Dinic(Sn)*1LL)*(k*1LL);
  long two=(s*1LL)*(h*1LL);
  //cout<<one<<endl;
  cout<<min(one,two)<<endl;
  return 0;
}