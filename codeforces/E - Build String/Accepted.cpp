/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2019 19:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 4800 KB                              
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
struct Edgee 
{
  int to, cost, cap, flow, backEdge;
};
struct MCMF 
{
  int s, t, n;
  vector<Edgee> g[mxN];
  MCMF(int _s, int _t, int _n) 
  {
    s = _s, t = _t, n = _n;
  }
  void addEdge(int u, int v, int cost, int cap) 
  {
    Edgee e1 = { v, cost, cap, 0, g[v].size() };
    Edgee e2 = { u, -cost, 0, 0, g[u].size() };
    g[u].push_back(e1); g[v].push_back(e2);
  }
  pair<int, int> minCostMaxFlow() 
  {
    int flow = 0, cost = 0;
    vector<int> state(n), from(n), from_edge(n), d(n);
    deque<int> q;
    while (true) 
    {
      for (int i = 0; i < n; i++)
        state[i] = 2, d[i] = inf, from[i] = -1;
      state[s] = 1; q.clear(); q.push_back(s); d[s] = 0;
      while (!q.empty()) 
      {
        int v = q.front(); q.pop_front(); state[v] = 0;
        for (int i = 0; i < (int) g[v].size(); i++) 
        {
          Edgee e = g[v][i];
          if (e.flow >= e.cap || d[e.to] <= d[v] + e.cost)
            continue;
          int to = e.to; d[to] = d[v] + e.cost;
          from[to] = v; from_edge[to] = i;
          if (state[to] == 1) continue;
          if (!state[to] || (!q.empty() && d[q.front()] > d[to]))
            q.push_front(to);
          else q.push_back(to);
          state[to] = 1;
        }
      }
      if (d[t] == inf) break;
      int it = t, addflow = inf;
      while (it != s) 
      {
        addflow = min(addflow,
            g[from[it]][from_edge[it]].cap
            - g[from[it]][from_edge[it]].flow);
        it = from[it];
      }
      it = t;
      while (it != s) 
      {
        g[from[it]][from_edge[it]].flow += addflow;
        g[it][g[from[it]][from_edge[it]].backEdge].flow -= addflow;
        cost += g[from[it]][from_edge[it]].cost * addflow;
        it = from[it];
      }
      flow += addflow;
    }
    return {cost,flow};
  }
};
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
  MCMF M(sr,tr,tr+1);
  for(auto x:fk)
  {
    M.addEdge(x.a,x.b,x.c,x.d);
  }
  for(int i=1;i<=n;i++)
    M.addEdge(sz+n+i,tr,0,inf);
   pair<int,int>p=M.minCostMaxFlow();
  //if(p.second>sz)assert(0);
  if(p.second<sz)cout<<-1<<endl;
  else cout<<p.first<<endl;
  //cout<<p.first<<" "<<p.second<<endl;
  return 0;
}