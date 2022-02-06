/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/13/2018 21:35                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/342/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e8;
int n,m,sz[N+2],lev[N+2],mark[N+2];
int anc[N+2],ans[N+2];
vector<int>adj[N+2];
int reckon(int node,int par,int lv)
{
  sz[node]=1;lev[node]=lv;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    sz[node]+=reckon(x,node,lv+1);
  }
  return sz[node];
}
int find_center(int node,int par)
{
  int mx=-1,nx=-1;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    if(sz[x]>mx)mx=sz[x],nx=x;
  }
  if(mx<=sz[node]/2)return node;
  else return find_center(nx,node);
}
void centroid(int node,int par)
{
  int center=find_center(node,par);
  anc[center]=par;mark[center]=1;
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    centroid(x,center);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  reckon(1,-1,1);centroid(1,-1);
  for(int i=1;i<=n;i++)ans[i]=inf;int tmp=1;
  while(tmp!=-1)
  {
    ans[tmp]=min(ans[tmp],abs(lev[tmp]-lev[1]));
    tmp=anc[tmp];
  }
  while(m--)
  {
    int ty,nd;cin>>ty>>nd;
    if(ty==1)
    {
      int tmp=nd;
      while(nd!=-1)
      {
        ans[nd]=min(ans[nd],abs(lev[nd]-lev[tmp]));
        nd=anc[nd];
      }
    }
    else
    {
      int tmp=nd,pr=inf;
      while(nd!=-1)
      {
        pr=min(pr,abs(lev[nd]-lev[tmp])+ans[nd]);
        nd=anc[nd];
      }
      cout<<pr<<endl;
    }
  }
  return 0;
}