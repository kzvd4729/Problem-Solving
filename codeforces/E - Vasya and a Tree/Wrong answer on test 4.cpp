/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2018 00:37                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 54800 KB                             
*  problem: https://codeforces.com/contest/1076/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long bit[N+2],hgt[N+2],ans[N+2];
int n,ent[N+2],tim,ext[N+2];
vector<int>adj[N+2];
vector<pair<int,int> >qu[N+2];
void upd(int x,int vl)
{
  for( ;x<=n;x+=x&-x)
    bit[x]+=(vl*1LL);
}
long qry(int x)
{
  long ret=0;
  for( ;x>0;x-=x&-x)
    ret+=bit[x];
  return ret;
}
void dfs(int node,int par)
{
  ent[node]=++tim;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
  }
  ext[node]=tim;
}
void dds(int node,int par,int h)
{
  for(auto x:qu[node])
  {
    upd(ent[node],x.second);upd(ext[node]+1,-x.second);
    hgt[h+x.first+1]-=x.second;
  }
  upd(ent[node],hgt[h]);upd(ext[node]+1,-hgt[node]);hgt[h]=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dds(x,node,h+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  int q;cin>>q;
  while(q--)
  {
    int v,d,x;cin>>v>>d>>x;
    qu[v].push_back({d,x});
  }
  dfs(1,-1);dds(1,-1,0);
  for(int i=1;i<=n;i++)
    cout<<qry(ent[i])<<" ";
  return 0;
}