/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-20 13:52:50                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 69                                         memory_used (MB): 2.4                             
*  problem: https://vjudge.net/problem/LightOJ-1222
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=102;
int mat[N+2][N+2];
/************** Min Cost Max Flow ****************/
const int Inf=1e9;
struct Edge
{
  int to,cost,cap,flow,back;
};
vector<Edge>Adj[N+2];
void AddEdge(int u,int v,int cost,int cap)
{
  Edge e1={v,cost,cap,0,(int)Adj[v].size()};
  Edge e2={u,-cost,0,0,(int)Adj[u].size()};
  Adj[u].push_back(e1);Adj[v].push_back(e2);
}
pair<int,int>MCMF(int n,int Sr,int Sn)
{
  int flow=0,cost=0;deque<int>q;
  vector<int>state(n+1),from(n+1),from_edge(n+1),d(n+1);
  while(true)
  {
    for(int i=0;i<=n;i++)
      state[i]=2,d[i]=Inf,from[i]=-1;
    state[Sr]=1;q.clear();q.push_back(Sr);d[Sr]=0;
    while(q.size())
    {
      int v=q.front();q.pop_front();state[v]=0;
      for(int i=0;i<Adj[v].size();i++)
      {
        Edge e=Adj[v][i];
        if(e.flow>=e.cap||d[e.to]<=d[v]+e.cost)
          continue;
        int to=e.to;d[to]=d[v]+e.cost;
        from[to]=v;from_edge[to]=i;
        if(state[to]==1)continue;
        if(!state[to]||(!q.empty()&&d[q.front()]>d[to]))
            q.push_front(to);
        else q.push_back(to);
          state[to]=1;
      }
    }
    if(d[Sn]==Inf) break;
    int it=Sn,addflow=Inf;
    while(it!=Sr) 
    {
      int x=Adj[from[it]][from_edge[it]].cap;
      int y=Adj[from[it]][from_edge[it]].flow;
      addflow=min(addflow,x-y);
        it=from[it];
    }
    it=Sn;
    while(it!=Sr) 
    {
      Adj[from[it]][from_edge[it]].flow+=addflow;
      Adj[it][Adj[from[it]][from_edge[it]].back].flow-=addflow;
      cost+=Adj[from[it]][from_edge[it]].cost*addflow;
      it=from[it];
    }
    flow+=addflow;
  }
  return {cost,flow};
}
///////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;int sr=0,sn=n+n+1;
    for(int i=0;i<=N;i++)Adj[i].clear();
    for(int i=1;i<=n;i++)AddEdge(sr,i,0,1);
    for(int i=n+1;i<=n+n;i++)AddEdge(i,sn,0,1);
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        int x;cin>>x;
        AddEdge(i,j+n,-x,1);
      }
    }
    pair<int,int>p=MCMF(sn,sr,sn);
    cout<<"Case "<<++tc<<": "<<-p.first<<endl;
  }
  return 0;
}