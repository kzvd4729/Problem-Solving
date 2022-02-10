/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-20 16:25:22                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1351                                       memory_used (MB): 2.6                             
*  problem: https://vjudge.net/problem/LightOJ-1206
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500,inf=1e9;
int a,b;//number of nodes in left and right side(both numbered from 1).
int lft[N+2],rgt[N+2],dis[N+2];vector<int>adj[N+2];
void clear()
{
  for(int i=1;i<=a;i++)lft[i]=0,adj[i].clear();
  for(int i=1;i<=b;i++)rgt[i]=0;
}
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=a;i++)
  {
    if(!lft[i])q.push(i),dis[i]=0;else dis[i]=inf;
  }
  dis[0]=inf;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto v:adj[u])
    {
      if(dis[rgt[v]]<=dis[u]+1)continue;//keeping distance only for left side
      dis[rgt[v]]=dis[u]+1;if(rgt[v])q.push(rgt[v]);
    }
  }
  return dis[0]!=inf;
}
bool dfs(int u)
{
  if(!u)return true;
  for(auto v:adj[u])
  {
    if(dis[u]+1==dis[rgt[v]])
    {
      if(dfs(rgt[v])){lft[u]=v;rgt[v]=u;return true;}
    }
  }
  return false;
}
int hopkroft(void)
{
  int match=0;
  while(bfs())
  {
    for(int i=1;i<=a;i++)
    {
      if(dis[i])continue;if(dfs(i))match++;
    }
  }
  return match;
}
int aa[N+2],bb[N+2],cc[N+2],dd[N+2],tim[N+2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;string s;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>s>>aa[i]>>bb[i]>>cc[i]>>dd[i];
      int hh=(s[0]-'0')*10+(s[1]-'0'),mm=(s[3]-'0')*10+(s[4]-'0');
      tim[i]=hh*60+mm;
    }
    a=n,b=n;
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(tim[i]+abs(cc[i]-aa[i])+abs(dd[i]-bb[i])+abs(aa[j]-cc[i])+abs(bb[j]-dd[i])<tim[j])
          adj[i].push_back(j);
      }
    }
    cout<<"Case "<<++tc<<": "<<n-hopkroft()<<"\n";clear();
  }
  return 0;
}