/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2020 20:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 35600 KB                             
*  problem: https://codeforces.com/contest/543/problem/B
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
#include<unordered_map>
#define long long long
using namespace std;
const int N=3e3,R=1e9;
int d[N+2],n,ds[N+2][N+2],ans;
vector<int>adj[N+2];
void bfs(int s)
{
  for(int i=1;i<=n;i++)d[i]=R;
  queue<int>q;q.push(s);d[s]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
      if(d[u]+1<d[x])d[x]=d[u]+1,q.push(x);
  }
  for(int i=1;i<=n;i++)ds[s][i]=d[i];
}
int l1,l2;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  int s1,t1,s2,t2;cin>>s1>>t1>>l1>>s2>>t2>>l2;
  for(int i=1;i<=n;i++)bfs(i);
  if(ds[s1][t1]>l1||ds[s2][t2]>l2)cout<<-1<<endl,exit(0);
  ans=ds[s1][t1]+ds[s2][t2];
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      int df=ds[i][j];
      int a=min(ds[s1][i]+ds[j][t1],ds[t1][i]+ds[j][s1])+df;
      int b=min(ds[s2][i]+ds[j][t2],ds[t2][i]+ds[j][s2])+df;
      if(a<=l1&&b<=l2)ans=min(ans,a+b-df);
    }
  }
  cout<<m-ans<<endl;
  return 0;
}