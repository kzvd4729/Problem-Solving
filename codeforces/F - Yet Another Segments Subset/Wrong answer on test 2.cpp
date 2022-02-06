/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/16/2020 11:36                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 26600 KB                             
*  problem: https://codeforces.com/contest/1399/problem/F
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
const int N=1e6,inf=1e9;
bool used[N+2];int mt[N+2];
vector<int>adj[N+2];//only edge from left to right
bool tryKuhn(int v)
{
  if(used[v])return false;used[v]=true;
  for(auto u:adj[v])
  {
    if(mt[u]==-1||tryKuhn(mt[u]))
    {
      mt[u]=v;return true;
    }
  }
  return false;
}
bool usd[N+2];
int solve(int a,int b)
{
  for(int i=1;i<=b;i++)mt[i]=-1;
  for(int i=1;i<=a;i++)usd[i]=false;
  for(int i=1;i<=a;i++)
  {
    for(auto x:adj[i])
    {
      if(mt[x]!=-1)continue;
      mt[x]=i;usd[i]=true;break;
    }
  }
  for(int i=1;i<=a;i++)
  {
    if(usd[i])continue;
    for(int j=1;j<=a;j++)used[j]=false;
    tryKuhn(i);
  }
  int ret=0;
  for(int i=1;i<=b;i++)if(mt[i]!=-1)ret++;
  for(int i=1;i<=a;i++)adj[i].clear();
  return ret;
}
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i],adj[i].clear();
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(aa[i]>=aa[j]&&bb[i]<=bb[j])continue;
        if(aa[j]>=aa[i]&&bb[j]<=bb[i])continue;
        if(aa[i]>bb[j]||bb[i]<aa[j])continue;
        adj[i].push_back(j);
      }
    }
    cout<<n-solve(n,n)<<" ";
  }
  cout<<endl;
  return 0;
}