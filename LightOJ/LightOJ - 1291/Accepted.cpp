/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-26 15:23:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 386                                        memory_used (MB): 5.2                             
*  problem: https://vjudge.net/problem/LightOJ-1291
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=1e4;
map<pair<int,int>,int>mp;
int vs[N+2];
struct dfsSpanningTree
{
  vector<int>adj[N+2],tree[N+2];//rooted tree
  vector<pair<int,int> >br;
  vector<int>bkadj[N+2];//for back edge
  /*lca of two back edge node is one of the node*/

  int vis[N+2],lev[N+2];
  void clean(void)
  {
    br.clear();mp.clear();
    for(int i=0;i<=N;i++)
    {
      adj[i].clear(),tree[i].clear();
      bkadj[i].clear();
      vis[i]=0,lev[i]=0;
    }
  }
  dfsSpanningTree()
  {
    clean();
  }
  //check for disconnected graph.
  void dfs(int node,int par,int lv)
  {
    vis[node]=1,lev[node]=lv;
    for(auto x:adj[node])
    {
      if(x==par)continue;
      if(vis[x])
      {
        bkadj[node].push_back(x);
        bkadj[x].push_back(node);
      }
      else
      {
        tree[node].push_back(x);
        tree[x].push_back(node);
        dfs(x,node,lv+1);
      }
    }
  }
  int bridge(int node,int par)
  {
    int mn=1e9;
    for(auto x:bkadj[node])
      mn=min(mn,lev[x]);
    for(auto x:tree[node])
    {
      if(x==par)continue;
      mn=min(mn,bridge(x,node));
    }
    if(mn>=lev[node]&&par!=-1)
    {
      br.push_back({par,node});
      mp[{par,node}]=1;mp[{node,par}]=1;
    }
    return mn;
  }
  int cal(int node,int par)
  {
    int ret=0,now=0;
    for(int i=0;i<tree[node].size();i++)
    {
      int x=tree[node][i];
      if(x==par)continue;
      int ad=0;if(mp[{node,x}])ad=1;
      int ok=cal(x,node);
      ret+=max(ad,ok);
      if(ok+ad)now++;
    }
    if(now==1&&par==-1)ret++;
    return ret;
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    dfsSpanningTree sp;
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;u++,v++;
      sp.adj[u].push_back(v);
      sp.adj[v].push_back(u);
    }
    sp.dfs(1,-1,0);sp.bridge(1,-1);
    cout<<"Case "<<++tc<<": ";
    if(sp.br.size()==0)
    {
      cout<<0<<endl;continue;
    }
    memset(vs,0,sizeof(vs));
    int f=0,cnt;
    cnt=sp.cal(sp.br[0].first,-1);
    cout<<(cnt+1)/2<<endl;
    sp.clean();
  }
  return 0;
}