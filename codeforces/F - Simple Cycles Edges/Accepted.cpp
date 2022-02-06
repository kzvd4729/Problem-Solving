/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2019 17:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 22300 KB                             
*  problem: https://codeforces.com/contest/962/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int lev[N+2],vis[N+2],prnt[N+2],cnt[N+2];
vector<int>adj[N+2],tree[N+2],lst[N+2];
vector<pair<int,int> >bk,ans;
map<pair<int,int>,int>mp;
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv,prnt[node]=par;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(vis[x])bk.push_back({min(node,x),max(node,x)});
    else
    {
      tree[node].push_back(x);
      tree[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
void add(int node,int par)
{
  for(auto x:tree[node])
  {
    if(x==par)continue;
    add(x,node);cnt[node]+=cnt[x];
  }
}
void dds(int node,int par,int lv)
{
  for(auto v:lst[node])
  {
    if(lev[v]<lv)continue;
    ans.push_back({v,node});
    int x=node,u;
    while(true)
    {
      u=prnt[x];ans.push_back({u,x});if(u==v)break;
      x=u;
    }
  }
  for(auto x:tree[node])
  {
    if(x==par)continue;
    if(cnt[x]>1)dds(x,node,lev[x]);
    else dds(x,node,lv);
  }
}
int main()
{
  //freopen("inp.txt","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;if(u>v)swap(u,v);mp[{u,v}]=i;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  vector<int>rt;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    rt.push_back(i);dfs(i,-1,1);
  }
  sort(bk.begin(),bk.end());
  bk.erase(unique(bk.begin(),bk.end()),bk.end());
  for(auto &x:bk)
  {
    if(lev[x.first]>lev[x.second])swap(x.first,x.second);
    cnt[x.second]++,cnt[x.first]--;
    lst[x.second].push_back(x.first);
  }
//  for(auto x:bk)
//    cout<<x.first<<" ** "<<x.second<<endl;
  for(auto x:rt){add(x,-1);dds(x,-1,0);}
  vector<int>pr;
  for(auto x:ans)
    pr.push_back(mp[{min(x.first,x.second),max(x.first,x.second)}]);
  cout<<pr.size()<<endl;
  sort(pr.begin(),pr.end());
  for(auto x:pr)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}