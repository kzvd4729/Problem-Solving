/****************************************************************************************
*  @author: kzvd4729                                         created: 21-09-2018 18:21:57                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.49 sec                                        memory_used: 55.6M                                
*  problem: https://www.codechef.com/problems/ALGFLXFJ
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
const long inf=1e14;
int n,nd[N+2],tot,sz[N+2],mark[N+2],mx;
long ans[N+2];
vector<int>adj[N+2];
vector<pair<int,int> >qu[N+2];
pair<long,long>pp[N+2][2];
void dfs(int node,int par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    dfs(x,node);sz[node]+=sz[x];
  }
}
int find_center(int node,int par)
{
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    if(sz[x]>tot/2)return find_center(x,node);
  }
  return node;
}
void upd(int lv,long ds,int sub)
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
void add(int node,int par,long ds,int lv,int sub)
{
  upd(lv,ds,sub);mx=max(mx,lv);
  for(auto x:adj[node])
  {
    if(mark[x]||x==par)continue;
    add(x,node,ds+nd[x]*1LL,lv+1,sub);
  }
}
long qry(int lv,int sub)
{
  long ret=inf;
  if(pp[lv][0].first!=sub)ret=min(ret,pp[lv][0].second);
  if(pp[lv][1].first!=sub)ret=min(ret,pp[lv][1].second);
  return ret;
}
void cal(int node,int par,long ds,int lv,int con,int sub)
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
void centroid(int node,int par)
{
  tot=0;dfs(node,-1);
  int center=find_center(node,-1);
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
  for(int i=0;i<=mx;i++)
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
  scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&nd[i]);
  for(int i=1;i<n;i++)
  {
    int u,v;scanf("%d%d",&u,&v);
    adj[u].push_back(v);adj[v].push_back(u);
  }
  int q;scanf("%d",&q);for(int i=1;i<=q;i++)ans[i]=inf;
  for(int i=1;i<=N;i++)
  {
    pp[i][0]={inf,inf};
    pp[i][1]={inf,inf};
  }
  for(int i=1;i<=q;i++)
  {
    int v,k;scanf("%d%d",&v,&k);
    qu[v].push_back({k,i});
  }
  centroid(1,-1);
  for(int i=1;i<=q;i++)
  {
    if(ans[i]>=inf)printf("-1\n");
    else printf("%lld\n",ans[i]);
  }
  return 0;
}