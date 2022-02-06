/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/23/2020 17:57                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 577 ms                                          memory_used: 19400 KB                             
*  problem: https://codeforces.com/contest/372/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e5;
int cnt[4*N+8],sm[4*N+8],dsm[4*N+8];
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lo>rt||hi<lt)return;
  if(lo>=lt&&hi<=rt)
  {
    cnt[node]+=vl;
    if(cnt[node])sm[node]=hi-lo+1;else sm[node]=dsm[node];
    return;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl),upd(node*2+1,md+1,hi,lt,rt,vl);
  dsm[node]=sm[node*2]+sm[node*2+1];
  if(cnt[node])sm[node]=hi-lo+1;else sm[node]=dsm[node];
}
vector<int>adj[N+2];
int sub[N+2],ent[N+2],tim,anc[N+2],par[N+2],lev[N+2];
void dfs(int n,int p,int l)
{
  sub[n]=1,par[n]=p,lev[n]=l;
  for(auto x:adj[n])
  {
    if(x==p)continue;dfs(x,n,l+1);sub[n]+=sub[x];
  }
}
void hld(int n,int p)
{
  ent[n]=++tim;//add to the ds
  int mx=-1,b=-1;
  for(auto x:adj[n])
  {
    if(x==p)continue;if(sub[x]>mx)mx=sub[x],b=x;
  }
  if(b!=-1){anc[b]=anc[n];hld(b,n);}
  for(auto x:adj[n])
  {
    if(x==p||x==b)continue;anc[x]=x;hld(x,n);
  }
}
void hQry(int u,int v,int n,int vl)//query on path u,v;
{
  while(true)
  {
    if(lev[u]<lev[v])swap(u,v);
    if(anc[u]==anc[v])
    {
      upd(1,1,n,ent[v],ent[u],vl);return;
    }
    if(lev[anc[u]]<lev[anc[v]])swap(u,v);
    upd(1,1,n,ent[anc[u]],ent[u],vl);
    u=par[anc[u]];
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  dfs(1,-1,0);anc[1]=1;hld(1,-1);
   int l=1;int ans=1;
  for(int i=2;i<=n;i++)
  {
    hQry(i,i-1,n,1);
    while(sm[1]>k)
    {
      hQry(l+1,l,n,-1);l++;
    }
    ans=max(ans,i-l+1);
  }
  cout<<ans<<endl;
  return 0;
}