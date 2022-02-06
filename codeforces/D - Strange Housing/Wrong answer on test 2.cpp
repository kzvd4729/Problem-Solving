/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2021 16:33                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 58700 KB                             
*  problem: https://codeforces.com/contest/1470/problem/D
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 vector<int>ad[N+2],tree[N+2];//rooted tree
vector<pair<int,int> >bked;
 int vis[N+2],lev[N+2];
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;
  for(auto x:ad[node])
  {
    if(x==par)continue;
    if(vis[x])bked.push_back({node,x});
    else
    {
      tree[node].push_back(x);
      tree[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
int sz,cl[N+2];
void color(int nd,int pr,int c)
{
  cl[nd]=c;sz++;
  for(auto x:tree[nd])
    if(x!=pr)color(x,nd,c^1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)ad[i].clear(),tree[i].clear(),vis[i]=0;bked.clear();
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
    sz=0;
    dfs(1,0,0);color(1,0,0);
     if(sz!=n){cout<<"NO\n";continue;}
     int f[]={0,0};
    for(auto x:bked)
    {
      if(cl[x.first]==cl[x.second])f[x.first]=1;
    }
    if(f[0]&&f[1]){cout<<"NO\n";continue;}
    cout<<"YES\n";int cnt=0,c;
        if(f[0]==0)c=0;else c=1;
    for(int i=1;i<=n;i++)
    {
      if(cl[i]==c)cnt++;
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++)
    {
      if(cl[i]==c)cout<<i<<" ";
    }
    cout<<endl;
  } 
  return 0;
}