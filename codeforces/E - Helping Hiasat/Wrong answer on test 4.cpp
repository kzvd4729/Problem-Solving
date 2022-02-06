/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2019 20:58                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/1105/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9,M=40;
int n,k,cnt,lft[N+N+2],rgt[M+M+2],dis[M+M+2];
set<string>st[N+2];
map<string,int>mp;
vector<int>adj[M+M+2];
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=k;i++)
  {
    if(!lft[i])
    {
      q.push(i);dis[i]=0;
    }
    else dis[i]=inf;
  }
  dis[0]=inf;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      int v=adj[u][i];
      if(dis[rgt[v]]<=dis[u]+1)continue;
      dis[rgt[v]]=dis[u]+1;
      if(rgt[v])q.push(rgt[v]);
    }
  }
  return dis[0]!=inf;
}
bool dfs(int node)
{
  if(node==0)return true;
  for(int i=0;i<adj[node].size();i++)
  {
    int v=adj[node][i];
    if(dis[node]+1==dis[rgt[v]])
    {
      if(dfs(rgt[v]))
      {
        lft[node]=v;rgt[v]=node;
        return true;
      }
    }
  }
  return false;
}
int Hopcroft(void)
{
  memset(lft,0,sizeof(lft));
  memset(rgt,0,sizeof(rgt));
  int matching=0;
  while(bfs())
  {
    for(int i=1;i<=k;i++)
    {
      if(dis[i])continue;
      if(dfs(i))
      {
        matching++;
      }
    }
  }
  return matching;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>k;int id=0;
  for(int i=1;i<=n;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
      ++id;
    else
    {
      string s;cin>>s;
      st[id].insert(s);
      if(!mp[s])mp[s]=++cnt;
    }
  }
  for(int i=1;i<=k;i++)
  {
    int f=0;
    for(int j=1;j<=id;j++)
    {
      for(auto x:st[j])
        if(mp[x]==i)f=1;
    }
    if(f)
    {
      for(int j=1;j<=id;j++)
      {
        for(auto x:st[j])
        {
          if(mp[x]!=i)
          {
            adj[i].push_back(mp[x]+k);
          }
        }
      }
    }
  }
  cout<<n-Hopcroft()<<endl;
  return 0;
}