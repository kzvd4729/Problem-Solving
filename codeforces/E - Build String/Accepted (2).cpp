/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2019 13:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4800 KB                              
*  problem: https://codeforces.com/contest/237/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3000;
const int mxN = 3000;
const int inf = 1e7;
int fr[30],mat[1000][1000];
string s[N+2];
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
struct fck
{
  int a,b,c,d;
};
vector<fck>fk;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string t;cin>>t;int sz=t.size();
  int n;cin>>n;
   int sr=0,cnt=sz+n+n;
  for(int i=1;i<=n;i++)
  {
    int cp;cin>>s[i]>>cp;
    set<char>st;
    memset(fr,0,sizeof(fr));
    for(auto x:s[i])
    {
      fr[x-'a']++;
      st.insert(x);
    }
    for(auto x:st)
    {
      mat[i][x-'a']=++cnt;
       fk.push_back({cnt,sz+i,0,fr[x-'a']});
    }
    fk.push_back({sz+i,sz+n+i,i,cp});
  }
  for(int i=1;i<=sz;i++)
  {
    fk.push_back({sr,i,0,1});
  }
  for(int i=0;i<sz;i++)
  {
    for(int j=1;j<=n;j++)
    {
      for(auto x:s[j])
      {
        if(t[i]==x)
        {
          fk.push_back({i+1,mat[j][x-'a'],0,1});
          break;
        }
      }
    }
  }
  int tr=++cnt;
  for(auto x:fk)
  {
    AddEdge(x.a,x.b,x.c,x.d);
  }
  for(int i=1;i<=n;i++)
    AddEdge(sz+n+i,tr,0,inf);
   pair<int,int>p=MCMF(tr,sr,tr);
  //if(p.second>sz)assert(0);
  if(p.second<sz)cout<<-1<<endl;
  else cout<<p.first<<endl;
  //cout<<p.first<<" "<<p.second<<endl;
  return 0;
}