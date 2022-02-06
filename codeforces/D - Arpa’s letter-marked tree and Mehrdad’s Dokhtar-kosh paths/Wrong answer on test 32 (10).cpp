/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2018 23:02                        
*  solution_verdict: Wrong answer on test 32                 language: GNU C++14                               
*  run_time: 1028 ms                                         memory_used: 213300 KB                            
*  problem: https://codeforces.com/contest/741/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int n,mask[N+2],sz[N+2],st[N+2],ed[N+2],vis[(1<<24)];
int tim,sack[(1<<24)],lin[N+2],lev[N+2],ans[N+2],f;
vector<pair<int,char> >adj[N+2];
vector<int>del;
void dfs(int node,int par,int msk,int lv)
{
  st[node]=++tim;sz[node]=1;lin[tim]=node;
  mask[node]=msk;lev[node]=lv;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    dfs(x.first,node,msk^(1<<(x.second-'a')),lv+1);
    sz[node]+=sz[x.first];
  }
  ed[node]=tim;
}
int dsu(int node,int par,int clr)
{
  int mx=-1,big=-1;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    if(sz[x.first]>mx)
      mx=sz[x.first],big=x.first;
  }
  for(auto x:adj[node])
  {
    if(x.first==par||x.first==big)continue;
    ans[node]=max(ans[node],dsu(x.first,node,1));
  }
  if(big!=-1)ans[node]=max(ans[node],dsu(big,node,0));
  if(f&&node==2604)cout<<ans[node]<<" "<<big<<" ";
  for(auto x:adj[node])
  {
    if(x.first==par||x.first==big)continue;
    for(int i=st[x.first];i<=ed[x.first];i++)
    {
      int msk=mask[lin[i]];
      ans[node]=max(ans[node],lev[lin[i]]+sack[msk]-2*lev[node]);
      for(int j=0;j<23;j++)
        ans[node]=max(ans[node],lev[lin[i]]+sack[(msk^(1<<j))]-2*lev[node]);
    }
    for(int i=st[x.first];i<=ed[x.first];i++)
    {
      int msk=mask[lin[i]];
      sack[msk]=max(sack[msk],lev[lin[i]]);
      if(!vis[msk])
      {
        del.push_back(msk);vis[msk]=1;
      }
    }
  }
  if(f&&node==2604)cout<<ans[node]<<" ";
  int tmp=mask[node];ans[node]=max(ans[node],sack[tmp]-lev[node]);
  for(int j=0;j<23;j++)
    ans[node]=max(ans[node],sack[(tmp^(1<<j))]-lev[node]);
  sack[tmp]=max(sack[tmp],lev[node]);
  del.push_back(tmp);
  if(f&&node==2604)cout<<ans[node]<<endl,exit(0);
  if(clr)
  {
    for(auto x:del)
    {
      sack[x]=0;vis[x]=0;
    }
    del.clear();
  }
  return ans[node];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++)
  {
    int x;char c;cin>>x>>c;
    if(i==5&&x==1&&c=='h')f=1;
    adj[i].push_back({x,c});
    adj[x].push_back({i,c});
  }
  dfs(1,-1,0,1);dsu(1,-1,1);
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}