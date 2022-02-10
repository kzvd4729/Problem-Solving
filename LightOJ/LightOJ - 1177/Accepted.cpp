/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-20 12:51:19                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 7                                          memory_used (MB): 2.4                             
*  problem: https://vjudge.net/problem/LightOJ-1177
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int N=100;
int sz,t,tc,n,x,cap[N+2];
int m;
/******************* Max Flow Min Cut *******************/
const int Inf=1e9;
struct Flow_Edge
{
  int a,b,f,c;
};
vector<Flow_Edge>Ed;
vector<int>FlowAdj[N+2];
void Flow_Add_Edge(int a,int b,int c)
{
  Flow_Edge e;e={a,b,0,c};
  FlowAdj[a].push_back(Ed.size());
  Ed.push_back(e);e={b,a,0,0};
  //e={b,a,0,c}//Birectional
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    Ed.clear();
    for(int i=0;i<=N;i++)FlowAdj[i].clear();
    for(int i=2;i<n;i++)
    {
      cin>>x;
      Flow_Add_Edge(i,n+i,x);
    }
    int a,b,c,d;
    for(int i=1;i<=m;i++)
    {
      cin>>a>>b>>c;
      if(a>b)swap(a,b);
      if(a==1)
        Flow_Add_Edge(a,b,c);
      else
      {
        Flow_Add_Edge(n+a,b,c);
        Flow_Add_Edge(n+b,a,c);
      }
    }
    Sr=1;Sn=n;
    cout<<"Case "<<++tc<<": "<<Dinic(N)<<endl;
  }
  return 0;
}