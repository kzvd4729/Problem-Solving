/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/25/2018 19:17                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/226/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,rt,lev[N+2],parent[N+2],sz[N+2];
int anc[N+2],tim,ent[N+2],lin[N+2];
vector<int>adj[N+2];
void dfs(int node,int par,int lv)
{
  sz[node]=1;lev[node]=lv;parent[node]=par;
  for(auto &x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,lv+1);sz[node]+=sz[x];
    if(sz[x]>=sz[adj[node][0]])swap(x,adj[node][0]);
  }
}
void hld(int node,int par)
{
  ent[node]=++tim;lin[tim]=node;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(x==adj[node][0])anc[x]=anc[node];
    else anc[x]=x;hld(x,node);
  }
}
void upd(int node,int lo,int hi,int pnode,int )
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(!x)
    {
      rt=i;continue;
    }
    adj[i].push_back(x);adj[x].push_back(i);
  }
  dfs(rt,-1,0);anc[rt]=rt;hld(rt,-1);
//  cout<<rt<<endl;
//  for(int i=1;i<=n;i++)
//    cout<<anc[i]<<" ";
//  cout<<endl;
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int x;cin>>x;
          }
    else
    {
          }
  }
  return 0;
}