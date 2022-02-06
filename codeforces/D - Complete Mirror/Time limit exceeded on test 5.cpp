/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/15/2020 18:50                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++17                               
*  run_time: 1000 ms                                         memory_used: 49400 KB                             
*  problem: https://codeforces.com/contest/1182/problem/D
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
const int mod=1000001011,b=1204003;
int hsh[N+2];
vector<int>adj[N+2];
map<int,int>mp[N+2];
bool ck(int node,int par)
{
  int mt=0;if(mp[node].count(par))return false;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(!ck(x,node))return mp[node][par]=false;
    if(mt==0)mt=hsh[x];
    else if(mt!=hsh[x])return mp[node][par]=false;
  }
  hsh[node]=(mt*1LL*b+adj[node].size())%mod;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)if(ck(i,-1))cout<<i<<endl,exit(0);
  cout<<-1<<endl;
  return 0;
}