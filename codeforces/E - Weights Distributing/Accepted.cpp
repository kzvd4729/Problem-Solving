/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2020 19:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 44400 KB                             
*  problem: https://codeforces.com/contest/1343/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
vector<int>adj[N+2];
int ds[N+2],aa[N+2],bb[N+2],cc[N+2],pp[N+2],n,m;
void bfs(int s)
{
  for(int i=1;i<=n;i++)ds[i]=inf;
  ds[s]=0;queue<int>q;q.push(s);
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      if(ds[u]+1<ds[x])
        ds[x]=ds[u]+1,q.push(x);
    }
  }
}
long qm[N+2];
long sum(int i,int j)
{
  if(j>m)return 1e18;
  return qm[j]-qm[i-1];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b,c;cin>>n>>m>>a>>b>>c;
    for(int i=1;i<=m;i++)cin>>pp[i];
    sort(pp+1,pp+m+1);
    for(int i=1;i<=m;i++)qm[i]=qm[i-1]+pp[i];
     for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);adj[v].push_back(u);
    }
    bfs(a);for(int i=1;i<=n;i++)aa[i]=ds[i];
    bfs(b);for(int i=1;i<=n;i++)bb[i]=ds[i];
    bfs(c);for(int i=1;i<=n;i++)cc[i]=ds[i];
     long ans=1LL*inf*inf;
    for(int i=1;i<=n;i++)
    {
      long now=qm[bb[i]]*2+sum(bb[i]+1,aa[i]+bb[i])+sum(aa[i]+bb[i]+1,aa[i]+bb[i]+cc[i]);
      ans=min(ans,now);
    }
    cout<<ans<<"\n";
  }
  return 0;
}