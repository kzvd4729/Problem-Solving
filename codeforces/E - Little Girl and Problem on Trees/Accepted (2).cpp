/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/02/2018 01:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 310 ms                                          memory_used: 12700 KB                             
*  problem: https://codeforces.com/contest/276/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,q,ent[N+2],ext[N+2],tim,lev[N+2];
int bit1[N+2],bit2[N+2];
vector<int>adj[N+2];
void dfs(int node,int par,int lv)
{
  ent[node]=++tim;lev[node]=lv;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,lv+1);
  }
  ext[node]=tim;
}
void upd1(int x,int vl){for( ;x<=N;x+=x&-x)bit1[x]+=vl;}
void upd2(int x,int vl){for( ;x<=N;x+=x&-x)bit2[x]+=vl;}
int qry1(int x){int ret=0;for( ;x>0;x-=x&-x)ret+=bit1[x];return ret;}
int qry2(int x){int ret=0;for( ;x>0;x-=x&-x)ret+=bit2[x];return ret;}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>q;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,1);
  while(q--)
  {
    int ty;cin>>ty;
    if(!ty)
    {
      int v,x,d;cin>>v>>x>>d;
      if(d>=lev[v]-1)
      {
        upd1(1,x);upd1(d-lev[v]+3,-x);
        int lt=ent[v]-(lev[v]-d+lev[v]-3);int rt=min(ext[v],ent[v]+d);
        if(rt<lt)continue;
        upd2(lt,x);upd2(rt+1,-x);
      }
      else
      {
        int lt=ent[v]-d,rt=min(ext[v],ent[v]+d);
        if(rt<lt)continue;
        upd2(lt,x);upd2(rt+1,-x);
      }
    }
    else
    {
      int v;cin>>v;
      cout<<qry1(lev[v])+qry2(ent[v])<<"\n";
    }
  }
  return 0;
}