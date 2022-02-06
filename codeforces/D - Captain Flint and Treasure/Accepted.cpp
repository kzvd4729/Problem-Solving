/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/01/2020 12:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 32500 KB                             
*  problem: https://codeforces.com/contest/1388/problem/D
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
const int N=2e5;
const int T=1e6;
vector<int>topo_sorted,topo[T+2];
int tp_vis[T+2];
void Topo_sort(int node)
{
  tp_vis[node]=1;
  for(auto x:topo[node])
  {
    if(tp_vis[x])continue;
    Topo_sort(x);
  }
  topo_sorted.push_back(node);
}
vector<int>Topological_Sort(int n)
{
  for(int i=1;i<=n;i++)
  {
    if(tp_vis[i])continue;
    Topo_sort(i);
  }
  reverse(topo_sorted.begin(),topo_sorted.end());
  return topo_sorted;
}
long a[N+2];int b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)
  {
    cin>>b[i];
    if(b[i]!=-1)topo[i].push_back(b[i]);
  }
  vector<int>v=Topological_Sort(n);
  long ans=0;vector<int>pr,tmp;
  for(auto x:v)
  {
    ans+=a[x];
    if(a[x]<0)tmp.push_back(x);
    else
    {
      pr.push_back(x);
      if(b[x]!=-1)a[b[x]]+=a[x];
    }
  }
  reverse(tmp.begin(),tmp.end());
  cout<<ans<<endl;
  for(auto x:pr)cout<<x<<" ";
  for(auto x:tmp)cout<<x<<" ";
    cout<<endl;
  return 0;
}