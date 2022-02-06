/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/07/2020 13:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 36300 KB                             
*  problem: https://codeforces.com/contest/796/problem/D
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
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],b[N+2],ds[N+2],tg[N+2];
vector<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,d;cin>>n>>k>>d;
  for(int i=1;i<=n;i++)ds[i]=1e9;
  queue<int>q;
  for(int i=1;i<=k;i++)
  {
    int x;cin>>x;
    if(ds[x])ds[x]=0,tg[x]=x,q.push(x);
  }
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
    a[i]=u,b[i]=v;
  }
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      if(ds[u]+1<ds[x])
      {
        ds[x]=ds[u]+1;q.push(x);tg[x]=tg[u];
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++)
    if(tg[a[i]]!=tg[b[i]])ans++;
  cout<<ans<<endl;
  for(int i=1;i<n;i++)
    if(tg[a[i]]!=tg[b[i]])cout<<i<<" ";
  cout<<endl;
  return 0;
}