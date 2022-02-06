/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2019 23:00                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 238200 KB                            
*  problem: https://codeforces.com/contest/1045/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int n;
pair<int,int>cr(int u,int v)
{
  return {min(u,v),max(u,v)};
}
vector<int>adj[N+2],tree[N+2];//rooted tree
vector<int>bkadj[N+2];//edges doesn't belong to the tree(end nodes are in a chain)
int vis[N+2],lev[N+2];
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(vis[x])
    {
      bkadj[node].push_back(x);bkadj[x].push_back(node);
    }
    else
    {
      tree[node].push_back(x);tree[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
vector<pair<int,int> >ed;stack<pair<int,int> >st;map<pair<int,int>,int>mp;
int del(int node,int par)
{
  int sz=st.size(),mn=inf;
  for(auto x:tree[node])if(x!=par)mn=min(mn,del(x,node));
  if(mn==lev[node])
  {
    ++n;set<int>s;
    while(st.size()>sz)
    {
      pair<int,int>p=st.top();st.pop();mp[p]=1;s.insert(p.first);s.insert(p.second);
    }
    for(auto x:s)ed.push_back({x,n});
  }
  for(auto x:bkadj[node])
  {
    mn=min(mn,lev[x]);if(lev[x]<lev[node])st.push(cr(x,node));
  }
  if(mn<lev[node])st.push(cr(node,par));
  return mn;
}
//..............................................................................
int sp[N+2][21],ds[N+2][21];
vector<pair<int,int> >vec[N+2];
void reckon(int n,int p,int h,int d)
{
  sp[n][0]=p;lev[n]=h;ds[n][0]=d;
  for(auto x:vec[n])if(x.first!=p)reckon(x.first,n,h+1,x.second);
}
void sparse(int n)
{
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(sp[i][j-1]!=-1)
      {
        ds[i][j]=ds[i][j-1]+ds[sp[i][j-1]][j-1];
        sp[i][j]=sp[sp[i][j-1]][j-1];
      }
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);int d=0;
  for(int i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
    {
      d+=ds[u][i];u=sp[u][i];
    }
  }
  if(u==v)return d;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    d+=ds[u][i]+ds[v][i];u=sp[u][i],v=sp[v][i];
  }
  return d+ds[u][0]+ds[v][0];
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,q;cin>>n>>m>>q;int nn=n;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;ed.push_back(cr(u,v));
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,0);del(1,-1);
  for(int i=1;i<=n;i++)adj[i].clear();
  for(auto x:ed)
  {
    if(mp[x])continue;int cs=2;
    if(x.first>nn||x.second>nn)cs=1;
    //cout<<x.first<<" --> "<<x.second<<endl;
    vec[x.first].push_back({x.second,cs});
    vec[x.second].push_back({x.first,cs});
  }
  reckon(1,-1,0,0);sparse(n);
  while(q--)
  {
    int u,v;cin>>u>>v;cout<<lca(u,v)/2<<"\n";
  }
  return 0;
}