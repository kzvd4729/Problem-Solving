/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2018 19:26                        
*  solution_verdict: Wrong answer on test 50                 language: GNU C++17                               
*  run_time: 1214 ms                                         memory_used: 15300 KB                             
*  problem: https://codeforces.com/contest/246/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,st[N+2],ed[N+2],lin[N+2],fr[N+2];
int hg[N+2],tim,sz[N+2],ans[N+2];
vector<int>adj[N+2],rt;
vector<pair<int,int> >qu[N+2];
map<string,int>mp[N+2];
string s[N+2];
void reckon(int node,int h)
{
  ++tim;
  lin[tim]=node;
  st[node]=tim;
  hg[node]=h;
  sz[node]=1;
  for(auto x:adj[node])
  {
    reckon(x,h+1);
    sz[node]+=sz[x];
  }
  ed[node]=tim;
}
void dfs(int node,int clr)
{
  int mx=-1,spc=-1;
  for(auto x:adj[node])
    if(sz[x]>mx)
      mx=sz[x],spc=x;
  for(auto x:adj[node])
    if(x!=spc)
      dfs(x,1);
  if(spc!=-1)dfs(spc,0);
  for(auto x:adj[node])
  {
    if(x==spc)continue;
    for(int i=st[x];i<=ed[x];i++)
    {
      int tmp=lin[i];
      mp[hg[tmp]][s[tmp]]++;
      if(mp[hg[tmp]][s[tmp]]==1)fr[hg[tmp]]++;
    }
  }
  mp[hg[node]][s[node]]++;
  if(mp[hg[node]][s[node]]==1)fr[hg[node]]++;
   for(auto xx:qu[node])
    ans[xx.second]=fr[hg[node]+xx.first];
  if(clr)
  {
    for(int i=st[node];i<=ed[node];i++)
    {
      int tmp=lin[i];
      mp[hg[tmp]][s[tmp]]--;
      if(mp[hg[tmp]][s[tmp]]==0)fr[hg[tmp]]--;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>s[i]>>x;
    if(!x)rt.push_back(i);
    else adj[x].push_back(i);
  }
  for(auto x:rt)
    reckon(x,1);
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int vi,ki;cin>>vi>>ki;
    qu[vi].push_back({ki,i});
  }
  for(auto x:rt)
    dfs(x,1);
  for(int i=1;i<=q;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}