/****************************************************************************************
*  @author: kzvd4729                                         created: 11-04-2019 22:40:03                      
*  solution_verdict: Run Time Error(SIGABRT)                 language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/APRIL19A/problems/XORMIN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,cnt=2;
int ww[N+2],tim,ent[N+2],ext[N+2],sz;
int rt[N+2],tr[200000*25+2][3],rev[N+2];
vector<int>bse[N+2],seg[N+2];
vector<int>adj[N+2];
void add(int x,int pr)
{
  int now=sz;
  for(int i=21;i>=0;i--)
  {
    bool z=(x&(1<<i));
    int nw=++sz;tr[nw][cnt]=tr[tr[pr][z]][cnt]+1;
    tr[now][z]=nw;tr[now][z^1]=tr[pr][z^1];
    now=nw;pr=tr[pr][z];
  }
}
int qry(int x,int on,int tw)
{
  int ret=0;
  for(int i=21;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if(tr[tr[tw][z^1]][cnt]-tr[tr[on][z^1]][cnt])
    {
      ret|=(1<<i);tw=tr[tw][z^1];
      on=tr[on][z^1];
    }
    else tw=tr[tw][z],on=tr[on][z];
  }
  return ret;
}
void build(int id,int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[id][node]=bse[id][lo-1];
    return ;
  }
  int md=(lo+hi)/2;
  build(id,node*2,lo,md);build(id,node*2+1,md+1,hi);
  seg[id][node]=min(seg[id][node*2],seg[id][node*2+1]);
}
int query(int id,int node,int lo,int hi,int lt,int rt)
{
  if(bse[id][lo-1]>rt||bse[id][hi-1]<lt)return 1e9;
  if(bse[id][lo-1]>=lt&&bse[id][hi-1]<=rt)return seg[id][node];
  int md=(lo+hi)/2;
  return min(query(id,node*2,lo,md,lt,rt),query(id,node*2+1,md+1,hi,lt,rt));
}
void dfs(int node,int par)
{
  ent[node]=++tim;rt[tim]=++sz;
  add(ww[node],rt[tim-1]);rev[tim]=node;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
  }
  ext[node]=tim;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,q;cin>>n>>q;
    for(int i=0;i<=n*25;i++)
      for(int j=0;j<3;j++)
        tr[i][j]=0;
    for(int i=1;i<=n;i++)
      cin>>ww[i],adj[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    tim=0,sz=0;dfs(1,-1);vector<int>tmp;
    for(int i=1;i<=n;i++)
    {
      tmp.push_back(ww[i]);
      bse[ww[i]].push_back(ent[i]);
    }
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for(auto x:tmp)
    {
      sort(bse[x].begin(),bse[x].end());
      int hi=bse[x].size();seg[x].resize(5*hi+2);
      build(x,1,1,hi);
    }
    int vl=0,vr=0;
    while(q--)
    {
      int v,k;cin>>v>>k;v^=vr;k^=vl;
      vl=qry(k,rt[ent[v]-1],rt[ext[v]]);
      vr=rev[query((vl^k),1,1,bse[(vl^k)].size(),ent[v],ext[v])];
      cout<<vr<<" "<<vl<<"\n";
    }
    for(auto x:tmp)
      bse[x].clear(),seg[x].clear();
  }
  return 0;
}