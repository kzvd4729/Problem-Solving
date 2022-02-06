/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/09/2020 13:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 39600 KB                             
*  problem: https://codeforces.com/contest/663/problem/C
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
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int cl[N+2],f,vs[N+2];
vector<int>ans(N+2);
vector<pair<int,int> >ad[N+2];
void dfs(int nd,int c)
{
  if(cl[nd]!=-1)
  {
    if(cl[nd]!=c)f=1;return ;
  }
  cl[nd]=c;
  for(auto x:ad[nd])dfs(x.first,c^x.second);
}
int a,b;vector<int>tmp;
void dfs2(int nd)
{
  tmp.push_back(nd);vs[nd]=1;
  if(cl[nd]==0)a++;else b++;
  for(auto x:ad[nd])
    if(vs[x.first]==0)dfs2(x.first);
}
void cal(vector<vector<int> >v,int n)
{
  for(int i=1;i<=n;i++)ad[i].clear(),cl[i]=-1,vs[i]=0;
  for(auto x:v)
  {
    ad[x[0]].push_back({x[1],x[2]});
    ad[x[1]].push_back({x[0],x[2]});
  }
  f=0;
  for(int i=1;i<=n;i++)
  {
    if(cl[i]==-1)dfs(i,0);
  }
  if(f)return ;vector<int>pr;
  for(int i=1;i<=n;i++)
  {
    if(vs[i])continue;
    tmp.clear(),a=0,b=0;dfs2(i);
    if(a<=b)
    {
      for(auto x:tmp)if(cl[x]==0)pr.push_back(x);
    }
    else
    {
      for(auto x:tmp)if(cl[x]==1)pr.push_back(x); 
    }
  }
  if((int)pr.size()<(int)ans.size())ans=pr;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;vector<vector<int> >a,b;
  for(int i=1;i<=m;i++)
  {
    int u,v;char c;cin>>u>>v>>c;
    if(c=='B')
    {
      a.push_back({u,v,0});
      b.push_back({u,v,1});
    }
    else
    {
      a.push_back({u,v,1});
      b.push_back({u,v,0});
    }
  }
  cal(a,n);cal(b,n);
  if((int)ans.size()>N)cout<<-1<<endl;
  else
  {
    cout<<(int)ans.size()<<'\n';
    for(auto x:ans)cout<<x<<" ";
      cout<<endl;
  }
  return 0;
}