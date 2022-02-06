/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/08/2020 22:24                        
*  solution_verdict: Wrong answer on pretest 7               language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 17800 KB                             
*  problem: https://codeforces.com/contest/1407/problem/E
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
const int N=5e5,inf=1e9;
vector<pair<int,int> >ad[N+2],rv[N+2];
int n,a[N+2],b[N+2],c[N+2];
void dfs(int nd)
{
  if(nd==n)return;
  if(a[nd]>=b[nd])
  {
    for(auto x:ad[nd])
    {
      if(x.second)continue;
      if(max(a[x.first],b[x.first])==a[nd]-1)
      {
        dfs(x.first);break;
      }
    }
  }
  else
  {
    for(auto x:ad[nd])
    {
      if(!x.second)continue;
      if(max(a[x.first],b[x.first])==b[nd]-1)
      {
        c[nd]=1;
        dfs(x.first);break;
      }
    }
  }
}
void bfs()
{
  for(int i=1;i<=n;i++)a[i]=inf,b[i]=inf;
  a[n]=0;b[n]=0;queue<int>q;q.push(n);
    while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:rv[u])
    {
      if(x.second==0)
      {
        if(max(a[u],b[u])+1<a[x.first])
        {
          a[x.first]=max(a[u],b[u])+1;
          if(a[x.first]<inf&&b[x.first]<inf)q.push(x.first);
        }
      }
      else
      {
        if(max(a[u],b[u])+1<b[x.first])
        {
          b[x.first]=max(a[u],b[u])+1;
          if(a[x.first]<inf&&b[x.first]<inf)q.push(x.first);
        }
      }
    }
  }
  int ans=max(a[1],b[1]);if(ans==inf)ans=-1;
  //for(int i=1;i<=n;i++)cout<<a[i]<<" "<<b[i]<<endl;
  cout<<ans<<endl;
  if(ans==-1)
  {
    for(int i=1;i<=n;i++)
    {
      if(a[i]==inf)cout<<0;
      else cout<<1;
    }
    cout<<endl;
  }
  else
  {
    dfs(1);
    for(int i=1;i<=n;i++)cout<<c[i];
      cout<<endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;vector<vector<int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;ed.push_back({u,v,w});
    rv[v].push_back({u,w});
    ad[u].push_back({v,w});
  }
  bfs();for(int i=1;i<=n;i++)ad[i].clear();
  for(auto x:ed)
  {
   }
  return 0;
}