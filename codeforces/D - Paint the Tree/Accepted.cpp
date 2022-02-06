/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/13/2019 15:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 217 ms                                          memory_used: 37700 KB                             
*  problem: https://codeforces.com/contest/1244/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[3][N+2],ln[N+2],col[N+2];
vector<int>adj[N+2];
void no(){cout<<-1<<endl,exit(0);}
void dfs(int node,int par,int h)
{
  ln[h]=node;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,h+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n;i++)cin>>aa[0][i];
  for(int i=0;i<n;i++)cin>>aa[1][i];
  for(int i=0;i<n;i++)cin>>aa[2][i];
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int rt=0;
  for(int i=0;i<n;i++)
  {
    if(adj[i].size()>2)no();
    if(adj[i].size()==1)rt=i;
  }
  dfs(rt,-1,0);long ans=1e18;
  vector<int>v={0,1,2},p;
  do
  {
    long now=0;
    for(int i=0;i<n;i++)
      now+=1LL*aa[v[i%3]][ln[i]];
    if(now<ans)ans=now,p=v;
  }while(next_permutation(v.begin(),v.end()));
  cout<<ans<<endl;
  for(int i=0;i<n;i++)
    col[ln[i]]=p[i%3];
  for(int i=0;i<n;i++)
    cout<<col[i]+1<<" ";
  cout<<endl;
   return 0;
}