/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-20 12:04:48                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 231                                        memory_used (MB): 2.7                             
*  problem: https://vjudge.net/problem/LightOJ-1156
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=2e9;
const int N=1e2;
int t,tc,d,ln,n,sz;
struct data
{
  int ds,ty;
  int in,out;
}arr[N+2];
string s;

/******************* Max Flow Min Cut *******************/
const int Inf=1e9;
struct Flow_Edge
{
  int a,b,f,c;
};
vector<Flow_Edge>Ed;
vector<int>FlowAdj[4*N+2];
void Flow_Add_Edge(int a,int b,int c)
{
  Flow_Edge e;e={a,b,0,c};
  FlowAdj[a].push_back(Ed.size());
  Ed.push_back(e);e={b,a,0,0};
  //e={b,a,0,c}//Birectional
  FlowAdj[b].push_back(Ed.size());
  Ed.push_back(e);
}
int FlowDis[4*N+2],Sr,Sn,Pt[4*N+2];
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
void make_graph(int dist)
{
  for(int i=0;i<=sz;i++)
    FlowAdj[i].clear();
  Ed.clear();
  for(int i=1;i<n;i++)
    Flow_Add_Edge(arr[i].in,arr[i].out,arr[i].ty);
  for(int i=0;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      if(arr[j].ds-arr[i].ds<=dist)
        Flow_Add_Edge(arr[i].out,arr[j].in,2);
}
int solve(void)
{
  Sr=0;
  Sn=++sz;
  arr[Sr].ds=0,arr[Sr].in=Sr,arr[Sr].out=Sr,arr[Sr].ty=2;
  n++;
  arr[n].ds=ln,arr[n].in=Sn,arr[n].out=Sn,arr[n].ty=2;
  int lo=0,hi=2e9,md;
  while(hi-lo>2)
  {
    int md=(lo+hi)/2;
    make_graph(md);
    if(Dinic(sz)>=2)hi=md;
    else lo=md;
  }
  for(int md=lo;md<=hi;md++)
  {
    make_graph(md);
    if(Dinic(sz)>=2)
      return md;
  }
  return -1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>ln;
    sz=0;
    for(int i=1;i<=n;i++)
    {
      cin>>s;
      d=0;
      for(int i=2;i<s.size();i++)
        d=d*10+s[i]-'0';
      if(s[0]=='B')arr[i].ty=2;
      else arr[i].ty=1;
      arr[i].ds=d;
      arr[i].in=++sz;
      arr[i].out=++sz;
    }
    cout<<"Case "<<++tc<<": "<<solve()<<endl;
  }
  return 0;
}