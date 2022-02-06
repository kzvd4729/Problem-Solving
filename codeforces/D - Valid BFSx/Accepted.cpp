/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 21:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 14700 KB                             
*  problem: https://codeforces.com/contest/1037/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,level[N+2],vis[N+2];
vector<int>adj[N+2],lev[N+2];
void dfs(int node,int par,int h)
{
  level[node]=h;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    dfs(xx,node,h+1);
  }
}
void inv(void)
{
  cout<<"NO"<<endl;
  exit(0);
}
void ck(int l1,int l2)
{
  int pt=0;
  for(int i=0;i<lev[l1].size();i++)
  {
    int nd=lev[l1][i];
    vector<int>v1,v2;
    for(auto x:adj[nd])
    {
      if(level[x]-1==level[nd])
        v1.push_back(x);
    }
    for(int j=pt;j<pt+v1.size();j++)
    {
      if(j>=lev[l2].size())inv();
      v2.push_back(lev[l2][j]);
    }
    pt+=v1.size();
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
//    cout<<endl;
//    for(auto z:v1)cout<<z<<" ";
//    cout<<endl;
//    for(auto z:v2)cout<<z<<" ";
//    cout<<endl;
//    cout<<endl;
    if(v1!=v2)inv();
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1,1);int mx=0;
  int now=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;mx=max(mx,level[x]);
    if(i==1&&x!=1)inv();
    if(vis[x])inv();vis[x]=1;
    if(level[x]>=now)now=level[x];
    else inv();
    lev[level[x]].push_back(x);
  }
  for(int i=1;i<mx;i++)
    ck(i,i+1);
  cout<<"YES"<<endl;
  return 0;
}