/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-26 17:15:10                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 4                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1176
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
int t,tc,n,m;
int lft[52],rgt[302],dis[52];
string s1,s2;
map<string,int>s;
struct segment
{
  int l,r;
}seg[7];
vector<int>adj[52];
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=m;i++)
  {
    if(lft[i]==0)
    {
      dis[i]=0;
      q.push(i);
    }
    else dis[i]=inf;
  }
  dis[0]=inf;
  while(q.size())
  {
    int u=q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      int v=adj[u][i];
      if(dis[rgt[v]]==inf)
      {
        dis[rgt[v]]=dis[u]+1;
        if(rgt[v])q.push(rgt[v]);
      }
    }
  }
  return dis[0]!=inf;
}
bool dfs(int u)
{
  if(!u)return true;
  for(int i=0;i<adj[u].size();i++)
  {
    int v=adj[u][i];
    if(dis[rgt[v]]!=dis[u]+1)continue;
    if(dfs(rgt[v]))
    {
      lft[u]=v;
      rgt[v]=u;
      return true;
    }
  }
  return false;
}
int Hopcroft(void)
{
  int matching=0;
  memset(lft,0,sizeof(lft));
  memset(rgt,0,sizeof(rgt));
  while(bfs())
  {
    for(int i=1;i<=m;i++)
    {
      if(dis[i])continue;
      if(dfs(i))
        matching++;
    }
  }
  return matching;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  s["XXL"]=1;
  s["XL"]=2;
  s["L"]=3;
  s["M"]=4;
  s["S"]=5;
  s["XS"]=6;

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=m;i++)adj[i].clear();
    int now=0;
    for(int i=1;i<=6;i++)
    {
      seg[i].l=now+1;
      seg[i].r=now+n;
      now+=n;
    }
    for(int i=1;i<=m;i++)
    {
      cin>>s1>>s2;
      segment sg=seg[s[s1]];
      for(int j=sg.l;j<=sg.r;j++)
        adj[i].push_back(j);
      sg=seg[s[s2]];
      for(int j=sg.l;j<=sg.r;j++)
        adj[i].push_back(j);

    }
    if(Hopcroft()==m)
      cout<<"Case "<<++tc<<": YES"<<endl;
    else cout<<"Case "<<++tc<<": NO"<<endl;
  }
  return 0;
}