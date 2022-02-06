/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/29/2019 21:04                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 5900 KB                              
*  problem: https://codeforces.com/contest/653/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int par[N+2],vis[N+2];
vector<int>adj[N+2];
void no(){cout<<"impossible"<<endl,exit(0);}
void yes(){cout<<"possible"<<endl,exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;if(u>v)swap(u,v);
    adj[u].push_back(v);
    if(u!=1)adj[v].push_back(u);
  }
  set<int>st;vector<int>er;
  for(int i=2;i<=n;i++)st.insert(i);
   for(int i=2;i<=n;i++)
  {
    if(st.find(i)==st.end())continue;
    queue<int>q;q.push(i);st.erase(i);par[i]=i;
    while(q.size())
    {
      int u=q.front();q.pop();
      for(auto x:adj[u])
        vis[x]=1;
      for(auto x:st)
      {
        if(vis[x])continue;q.push(x);
        par[x]=i;er.push_back(x);
      }
      for(auto x:er)st.erase(x);
      er.clear();
      for(auto x:adj[u])
        vis[x]=0;
    }
  }
//  for(int i=1;i<=n;i++)cout<<par[i]<<" ";
//  cout<<endl;
  if(st.size()>0)assert(0);
  for(int i=2;i<=n;i++)
    st.insert(par[i]);
  if(st.size()>n-1-adj[1].size())no();
  if(st.size()>k)no();
  for(auto x:adj[1])vis[x]=1;
   for(int i=2;i<=n;i++)
  {
    if(vis[i])continue;
    if(st.find(par[i])!=st.end())st.erase(par[i]);
  }
  if(st.size()!=0)no();yes();
  return 0;
}