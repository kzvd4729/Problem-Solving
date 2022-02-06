/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/01/2018 23:35                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/761/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=30;
int deg[N+2],id;long df[N+2];
vector<int>adj[N+2];
pair<int,int>ans[N+2];
void dfs(int node,int par,int r,int c,int ck)
{
  ans[node]={r,c};
  int f=0;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    if(f==0&&ck!=2)
      dfs(xx,node,r+df[++id],c,0),f++;
    else if(f==1&&ck!=3)
      dfs(xx,node,r,c+df[++id],1),f++;
    else if(f==2&&ck!=0)
      dfs(xx,node,r-df[++id],c,2),f++;
    else if(f==3&&ck!=1)
      dfs(xx,node,r,c-df[++id],3),f++;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++,deg[v]++;
  }
  int rt=1;
  for(int i=1;i<=n;i++)
  {
    if(deg[i]==4)rt=i;
    if(deg[i]>5)cout<<"NO"<<endl,exit(0);
  }
  df[1]=1;
  for(int i=2;i<=30;i++)
  {
    df[i]=df[i-1]*31LL;
    if(df[i]>1e16)df[i]=1;
  }
  reverse(df+1,df+31);
  dfs(rt,-1,0,0,5);cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  return 0;
}