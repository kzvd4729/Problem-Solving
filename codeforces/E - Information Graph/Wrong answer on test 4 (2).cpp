/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2018 10:09                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++11                               
*  run_time: 202 ms                                          memory_used: 9800 KB                              
*  problem: https://codeforces.com/contest/466/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,m,par[N+2],ty,emp[N+2],x,y,cnt,root[N+2];
int in[N+2],out[N+2],tim,isroot[N+2];
vector<pair<int,int> >qu;
vector<int>adj[N+2];
int find_root(int x)
{
  while(x!=root[x])
  {
    root[x]=root[root[x]];
    x=root[x];
  }
  return x;
}
void dfs(int node,int prr)
{
  in[node]=++tim;
  for(auto x:adj[node])
  {
    if(x==prr)continue;
    dfs(x,node);
  }
  out[node]=tim;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=N;i++)root[i]=i,isroot[i]=1;
  while(m--)
  {
    cin>>ty;
    if(ty==1)
    {
      cin>>x>>y;
      isroot[x]=0;
      adj[y].push_back(x);
      adj[x].push_back(y);
      par[x]=y;
      root[x]=y;
    }
    else if(ty==2)
    {
      cin>>x;
      emp[++cnt]=x;
    }
    else
    {
      cin>>x>>y;
      int xx=find_root(x);
      int yy=find_root(emp[y]);
      if(xx!=yy)qu.push_back({-1,-1});
      else qu.push_back({x,y});
    }
  }
  for(int i=1;i<=n;i++)
    if(isroot[i])dfs(i,-1);
//  for(int i=1;i<=n;i++)cout<<in[i]<<" ";
//  cout<<endl;
//  for(int i=1;i<=n;i++)cout<<out[i]<<" ";
//  cout<<endl;
  for(auto x:qu)
  {
    if(x.first==-1)
    {
      cout<<"NO"<<endl;
      continue;
    }
    int xx=find_root(x.first);
    int yy=find_root(emp[x.second]);
    if(xx!=yy)
    {
      cout<<"NO"<<endl;
      continue;
    }
    if(in[emp[x.second]]>=in[x.first]&&in[emp[x.second]]<=out[x.first])
      cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}