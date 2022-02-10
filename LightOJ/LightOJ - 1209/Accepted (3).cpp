/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-20 19:43:52                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 19                                         memory_used (MB): 2.5                             
*  problem: https://vjudge.net/problem/LightOJ-1209
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500,inf=1e9;

int a,b;//number of nodes in left and right side(both numbered from 1).
int lft[N+2],rgt[N+2],dis[N+2];vector<int>adj[N+2];
void clean()
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
vector<pair<string,string> >aa,bb;
bool isConflict(int i,int j)
{
  if(aa[i].first==bb[j].second||aa[i].second==bb[j].first)return true;
  return false;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int ta,tb,c;cin>>ta>>tb>>c;aa.clear(),bb.clear();
    for(int i=1;i<=c;i++)
    {
      string x,y;cin>>x>>y;
      if(x[0]=='M')aa.push_back({x,y});
      else bb.push_back({x,y});
    }
    for(int i=0;i<aa.size();i++)
    {
      for(int j=0;j<bb.size();j++)
      {
        if(isConflict(i,j))
        {
          adj[i+1].push_back(j+1);
          //cout<<i+1<<" "<<j+1<<endl;
        }
      }
    }
    a=aa.size(),b=bb.size();
    cout<<"Case "<<++tc<<": "<<c-hopkroft()<<"\n";clean();
  }
  return 0;
}