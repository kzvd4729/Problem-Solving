/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2019 18:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 686 ms                                          memory_used: 24000 KB                             
*  problem: https://codeforces.com/contest/1156/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int sz[N+2],tot,cnt[N+2],flag[N+2],ok[3],mark[N+2];
vector<pair<int,int> >adj[N+2];long ans=0;
void reckon(int node,int par)
{
  sz[node]=1;tot++;
  for(auto x:adj[node])
  {
    if(x.first==par||mark[x.first])continue;
    reckon(x.first,node);sz[node]+=sz[x.first];
  }
}
int find_center(int node,int par)
{
  for(auto x:adj[node])
  {
    if(x.first==par||mark[x.first])continue;
    if(sz[x.first]>tot/2)
      return find_center(x.first,node);
  }
  return node;
}
void cal(int bss,int node,int par,int f)
{
  cnt[bss]++;
  for(auto x:adj[node])
  {
    if(x.first==par||mark[x.first])continue;
    if(!x.second&&f)continue;
    cal(bss,x.first,node,x.second);
  }
}
void agn(int bss,int node,int par,int l,int o)
{
  ans++;
  if(o)
  {
    ans+=ok[1]*1LL;
    if(flag[bss])ans-=cnt[bss];
  }
  else
  {
    ans+=(ok[0]+ok[1]-cnt[bss])*1LL;
  }
  for(auto x:adj[node])
  {
    if(x.first==par||mark[x.first])continue;
    if(!l&&x.second)continue;
    agn(bss,x.first,node,x.second,o|x.second);
  }
}
void centroid(int node)
{
  tot=0;reckon(node,-1);
  int center=find_center(node,-1);
  mark[center]=1;
  //cout<<"center "<<center<<endl;
  ok[0]=0;ok[1]=0;
  for(auto x:adj[center])
  {
    if(mark[x.first])continue;
    flag[x.first]=x.second;cnt[x.first]=0;
    cal(x.first,x.first,-1,x.second);
    ok[flag[x.first]]+=cnt[x.first];
  }
  ans+=(ok[0]+ok[1])*1LL;
  for(auto x:adj[center])
  {
    if(mark[x.first])continue;
    agn(x.first,x.first,-1,x.second,x.second);
  }
  for(auto x:adj[center])
  {
    if(mark[x.first])continue;
    centroid(x.first);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  centroid(1);cout<<ans<<endl;
  return 0;
}