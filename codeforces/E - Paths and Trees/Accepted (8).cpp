/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2019 16:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 920 ms                                          memory_used: 131300 KB                            
*  problem: https://codeforces.com/contest/545/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e18;
long ds[N+2],qd[N+2],vs[N+2],ww[N+2],par[N+2];
vector<pair<long,long> >adj[N+2];
map<pair<long,long>,long>mp;
long _find(long x)
{
  if(x==par[x])return x;
  return par[x]=_find(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;vector<pair<long,pair<long,long> > >edge,tmp;
  for(long i=1;i<=m;i++)
  {
    long u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    mp[{u,v}]=mp[{v,u}]=i;ww[i]=w;
     edge.push_back({w,{u,v}});
  }
  for(long i=1;i<=n;i++)ds[i]=inf,par[i]=i;
  long st;cin>>st;ds[st]=0;queue<long>q;
  q.push(st);
  while(q.size())
  {
    long nd=q.front();q.pop();
    for(auto x:adj[nd])
    {
      if(ds[nd]+x.second<ds[x.first])
      {
        ds[x.first]=ds[nd]+x.second;
        q.push(x.first);
      }
    }
  }
  for(auto x:edge)
  {
    long cs=x.first,u=x.second.first,v=x.second.second;
    int f=0,g=0;
    if(ds[u]+cs==ds[v])tmp.push_back({cs,{u,v}}),f=1;
    if(ds[v]+cs==ds[u])tmp.push_back({cs,{v,u}}),g=1;
    if(f&&g)assert(0);
  }
  edge=tmp;sort(edge.begin(),edge.end());
  for(auto x:edge)
  {
    long cs=x.first,u=x.second.first,v=x.second.second;
    //cout<<u<<"-->"<<v<<endl;
  }
  vector<long>ans;long sm=0;memset(vs,0,sizeof(vs));
  for(auto x:edge)
  {
    long cs=x.first,u=x.second.first,v=x.second.second;
    if(vs[v])continue;
    ans.push_back(mp[{u,v}]);sm+=cs;vs[v]=1;
  }
  if(ans.size()!=n-1)assert(0);
  cout<<sm<<endl;long sm2=0;
  for(auto x:ans)
  {
    cout<<x<<" ";
    if(!x)assert(0);
    sm2+=ww[x];
  }
  cout<<endl;
  if(sm!=sm2)assert(0);
  return 0;
}