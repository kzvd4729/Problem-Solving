/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/07/2019 23:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 795 ms                                          memory_used: 31800 KB                             
*  problem: https://codeforces.com/contest/1133/problem/F2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int par[N+2],parent[N+2];
vector<int>adj[N+2];
int _find(int x)
{
  if(x==par[x])return x;
  return par[x]=_find(par[x]);
}
void dfs(int n,int p)
{
  parent[n]=p;
  for(auto x:adj[n])
  {
    if(x==p)continue;
    dfs(x,n);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,d;cin>>n>>m>>d;
  vector<pair<int,int> >ed;vector<int>on,tw;
  while(m--)
  {
    int u,v;cin>>u>>v;if(u>v)swap(u,v);
    if(u==1)on.push_back(v);
    else ed.push_back({u,v});
  }
  set<pair<int,int> >st;
  for(int i=1;i<=n;i++)par[i]=i;
  for(auto x:ed)
  {
    int r1=_find(x.first),r2=_find(x.second);
    if(r1==r2)continue;
    par[r1]=r2;st.insert(x);
    adj[x.first].push_back(x.second);
    adj[x.second].push_back(x.first);
  }
  for(int i=0;i<on.size();i++)
  {
    int u=1,v=on[i];
    int r1=_find(u),r2=_find(v);
    if(r1!=r2)
    {
      par[r1]=r2;st.insert({u,v});d--;
      adj[u].push_back(v);adj[v].push_back(u);
    }
    else tw.push_back(on[i]);
  }
  if(d<0)cout<<"NO"<<endl,exit(0);
  if(tw.size()<d)cout<<"NO"<<endl,exit(0);
  if(d==0)
  {
    cout<<"YES"<<endl;
    for(auto x:st)
      cout<<x.first<<" "<<x.second<<endl;
    exit(0);
  }
  dfs(1,-1);
  for(int i=0;i<tw.size();i++)
  {
    int v=tw[i];int u=parent[v];
    if(u==1)continue;if(u>v)swap(u,v);
    st.erase({u,v});st.insert({1,tw[i]});
    d--;if(d==0)break;
  }
  if(d)cout<<"NO"<<endl,exit(0);
  if(st.size()!=n-1)cout<<"NO"<<endl,exit(0);
  cout<<"YES"<<endl;
  for(auto x:st)
    cout<<x.first<<" "<<x.second<<endl;
  return 0;
}