/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/17/2020 21:42                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 295 ms                                          memory_used: 77000 KB                             
*  problem: https://codeforces.com/contest/1385/problem/G
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
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
int a[N+2],b[N+2],fr[N+2],vis[N+2],cl[N+2];
vector<int>pa[N+2],pb[N+2],bf;
vector<pair<int,int> >adj[N+2];
int f;
void dfs(int node,int c)
{
  if(vis[node]){if(cl[node]!=c)f=1;return;}
  bf.push_back(node);cl[node]=c;vis[node]=1;
  for(auto x:adj[node])
    dfs(x.first,c^x.second);
}
vector<int>ans;
bool solve()
{
  int n;cin>>n;
   for(int i=1;i<=n;i++)pa[i].clear(),pb[i].clear(),adj[i].clear(),fr[i]=0,vis[i]=0;
  f=0;ans.clear();
   for(int i=1;i<=n;i++)cin>>a[i],fr[a[i]]++,pa[a[i]].push_back(i);
  for(int i=1;i<=n;i++)cin>>b[i],fr[b[i]]++,pb[b[i]].push_back(i);
   for(int i=1;i<=n;i++)if(fr[i]!=2)return false;
   for(int i=1;i<=n;i++)
  {
    if(pa[i].size()==2)
    {
      adj[pa[i][0]].push_back({pa[i][1],1});
      adj[pa[i][1]].push_back({pa[i][0],1});
    }
    else if(pb[i].size()==2)
    {
      adj[pb[i][0]].push_back({pb[i][1],1});
      adj[pb[i][1]].push_back({pb[i][0],1});
    }
    else
    {
      adj[pa[i][0]].push_back({pb[i][0],0});
      adj[pb[i][0]].push_back({pa[i][0],0});
    }
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    bf.clear();dfs(i,0);if(f)return false;
     int cnt=0;
    for(auto x:bf)cnt+=cl[x];
     int c=0;
    if(cnt<bf.size()-cnt)c=1;
     for(auto x:bf)if(cl[x]==c)ans.push_back(x);
   }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    if(solve())
    {
      cout<<ans.size()<<endl;
      for(auto x:ans)cout<<x<<" ";cout<<endl;
    }
    else cout<<-1<<endl;
  }
  return 0;
}