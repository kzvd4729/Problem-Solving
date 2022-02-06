/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/01/2020 21:04                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 374 ms                                          memory_used: 51100 KB                             
*  problem: https://codeforces.com/contest/1005/problem/F
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#define long long long 
using namespace std;
const int N=1e6,inf=1e9;
int n,d[N+2];
vector<int>adj[N+2];
void bfs(int nd)
{
  for(int i=1;i<=n;i++)d[i]=inf;
  queue<int>q;q.push(1);d[1]=0;
   while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      if(d[u]+1<d[x])d[x]=d[u]+1,q.push(x);
    }
  }
}
vector<pair<int,int> >par[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,k;cin>>n>>m>>k;vector<vector<int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
    ed.push_back({u,v,i});
  }
  bfs(1);
  for(auto x:ed)
  {
    if(d[x[0]]+1==d[x[1]])par[x[1]].push_back({x[0],x[2]});
    else if(d[x[1]]+1==d[x[0]])par[x[0]].push_back({x[1],x[2]});
  }
  vector<vector<int> >ans;
  for(int i=2;i<=n;i++)
  {
    if(ans.size()==0)
    {
      ans.resize((int)par[i].size());
      for(int j=0;j<par[i].size();j++)
        ans[j].push_back(par[i][j].second);
      while(ans.size()>k)ans.pop_back();
      continue;
    }
    int sz=ans.size();
    for(int j=sz;j<min(k,sz*(int)par[i].size());j++)
      ans.push_back(ans[j%sz]);
     for(int j=0;j<ans.size();j++)
      ans[j].push_back(par[i][j/sz].second);
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
  {
    sort(x.begin(),x.end());x.push_back(-1);
    int pt=0;
    for(int i=1;i<=m;i++)
    {
      if(i==x[pt])cout<<1,pt++;
      else cout<<0;
    }
    cout<<'\n';
  }
  return 0;
}