/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2020 14:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2916 ms                                         memory_used: 60800 KB                             
*  problem: https://codeforces.com/contest/633/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],tim,ent[N+2],ext[N+2],lin[N+2],lz[4*N+2],m;
vector<int>adj[N+2];
bitset<1000>seg[4*N+2],an;
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node][lin[lo]%m]=1;return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=seg[node*2]|seg[node*2+1];
}
void tooLazy(int node,int lo,int hi)
{
  if(!lz[node])return ;
  seg[node]=(seg[node]<<lz[node])|(seg[node]>>(m-lz[node]));
  seg[node]&=an;
  if(lo!=hi)
  {
    lz[node*2]=(lz[node*2]+lz[node])%m;
    lz[node*2+1]=(lz[node*2+1]+lz[node])%m;
  }
  lz[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,int ad)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[node]=(lz[node]+ad)%m;
    tooLazy(node,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,ad);
  upd(node*2+1,md+1,hi,lt,rt,ad);
   seg[node]=seg[node*2]|seg[node*2+1];
}
bool get(int node,int lo,int hi,int lt,int rt,int p)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return false;
  if(lo>=lt&&hi<=rt)
  {
    //cout<<p<<" "<<seg[node]<<endl;
    return seg[node][p];
  }
  int md=(lo+hi)/2;
  return get(node*2,lo,md,lt,rt,p)|get(node*2+1,md+1,hi,lt,rt,p);
}
void dfs(int node,int par)
{
  ent[node]=++tim;lin[tim]=aa[node];
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
  }
  ext[node]=tim;
}
bool isPrime(int x)
{
  for(int i=2;i<x;i++)if(x%i==0)return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=0;i<m;i++)an[i]=1;
  dfs(1,0);vector<int>prm;
  for(int i=2;i<=m;i++)
    if(isPrime(i))prm.push_back(i);
   build(1,1,n);
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      //cout<<seg[1]<<endl;
      int v,x;cin>>v>>x;
      upd(1,1,n,ent[v],ext[v],x%m);
      //cout<<seg[1]<<endl;
    }
    else
    {
      int v;cin>>v;int ans=0;
      //cout<<ent[v]<<" ** "<<ext[v]<<endl;
      for(auto p:prm)ans+=get(1,1,n,ent[v],ext[v],p);
      cout<<ans<<"\n";
    }
  }
  return 0;
}