/****************************************************************************************
*  @author: kzvd4729                                         created: 21-09-2018 17:32:03                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.46 sec                                        memory_used: 96.9M                                
*  problem: https://www.codechef.com/problems/ALGFLXFJ
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=6e5;
const long inf=1e14;
long n,nd[N+2],tot,sz[N+2],mark[N+2];
long ans[N+2];
vector<long>adj[N+2];
vector<pair<long,long> >qu[N+2];
multiset<long>st[N+2];
void dfs(long node,long par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    dfs(x,node);sz[node]+=sz[x];
  }
}
long find_center(long node,long par)
{
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    if(sz[x]>tot/2)return find_center(x,node);
  }
  return node;
}
void add(long node,long par,long ds,long lv)
{
  st[lv].insert(ds);
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    add(x,node,ds+nd[x]*1LL,lv+1);
  }
}
void rem(long node,long par,long ds,long lv)
{
  st[lv].erase(st[lv].find(ds));
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    rem(x,node,ds+nd[x]*1LL,lv+1);
  }
}
void cal(long node,long par,long ds,long lv,long con)
{
  for(auto x:qu[node])
  {
    if(x.first>=lv&&st[x.first-lv].size())
      ans[x.second]=min(ans[x.second],*st[x.first-lv].begin()+ds+con*1LL);
  }
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    cal(x,node,ds+nd[x]*1LL,lv+1,con);
  }
}
void centroid(long node,long par)
{
  tot=0;dfs(node,-1);
  long center=find_center(node,-1);
  mark[center]=1;
  st[0].insert(0);
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    add(x,-1,nd[x],1);
  }
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    rem(x,-1,nd[x],1);
    cal(x,-1,nd[x],1,nd[center]);
    add(x,-1,nd[x],1);
  }
  for(auto x:qu[center])
  {
    if(st[x.first].size())
      ans[x.second]=min(ans[x.second],*st[x.first].begin()+nd[node]*1LL);
  }
  for(long i=0;  ;i++)
  {
    if(st[i].size())st[i].clear();
    else break;
  }
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    centroid(x,center);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(long i=1;i<=n;i++)cin>>nd[i];
  for(long i=1;i<n;i++)
  {
    long u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  long q;cin>>q;for(long i=1;i<=q;i++)ans[i]=inf;
  for(long i=1;i<=q;i++)
  {
    long v,k;cin>>v>>k;
    qu[v].push_back({k,i});
  }
  centroid(1,-1);
  for(long i=1;i<=q;i++)
  {
    if(ans[i]>=inf)cout<<-1<<endl;
    else cout<<ans[i]<<endl;
  }
  return 0;
}