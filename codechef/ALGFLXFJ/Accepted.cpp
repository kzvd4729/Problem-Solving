/****************************************************************************************
*  @author: kzvd4729                                         created: 21-09-2018 18:00:32                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.64 sec                                        memory_used: 94.8M                                
*  problem: https://www.codechef.com/problems/ALGFLXFJ
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=6e5;
const long inf=1e14;
long n,nd[N+2],tot,sz[N+2],mark[N+2];
long ans[N+2],mx;
vector<long>adj[N+2];
vector<pair<long,long> >qu[N+2];
pair<long,long>pp[N+2][2];
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
void upd(long lv,long ds,int sub)
{
  if(pp[lv][0].first==sub)
    pp[lv][0]={sub,min(pp[lv][0].second,ds)};
  else if(pp[lv][1].first==sub)
    pp[lv][1]={sub,min(pp[lv][1].second,ds)};
  else if(pp[lv][0].second>pp[lv][1].second)
  {
    if(ds<pp[lv][0].second)
      pp[lv][0]={sub,ds};
  }
  else
  {
    if(ds<pp[lv][1].second)
      pp[lv][1]={sub,ds};
  }
}
void add(long node,long par,long ds,long lv,long sub)
{
  upd(lv,ds,sub);mx=max(mx,lv);
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    add(x,node,ds+nd[x]*1LL,lv+1,sub);
  }
}
long qry(long lv,long sub)
{
  long ret=inf;
  if(pp[lv][0].first!=sub)ret=min(ret,pp[lv][0].second);
  if(pp[lv][1].first!=sub)ret=min(ret,pp[lv][1].second);
  return ret;
}
void cal(long node,long par,long ds,long lv,long con,long sub)
{
  for(auto x:qu[node])
  {
    if(x.first>=lv)
    {
      ans[x.second]=min(ans[x.second],qry(x.first-lv,sub)+ds+con*1LL);
    }
  }
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    cal(x,node,ds+nd[x]*1LL,lv+1,con,sub);
  }
}
void centroid(long node,long par)
{
  tot=0;dfs(node,-1);
  long center=find_center(node,-1);
  mark[center]=1;
  pp[0][0]={center,0};
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    add(x,-1,nd[x],1,x);
  }
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    cal(x,-1,nd[x],1,nd[center],x);
    add(x,-1,nd[x],1,x);
  }
  for(auto x:qu[center])
  {
    ans[x.second]=min(ans[x.second],qry(x.first,-1)+nd[center]*1LL);
  }
  for(long i=0;i<=mx;i++)
  {
    pp[i][0]={inf,inf};
    pp[i][1]={inf,inf};
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
  for(int i=1;i<=N;i++)
  {
    pp[i][0]={inf,inf};
    pp[i][1]={inf,inf};
  }
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