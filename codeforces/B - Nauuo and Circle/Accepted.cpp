/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2020 00:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 23300 KB                             
*  problem: https://codeforces.com/contest/1172/problem/B
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
const int N=2e5;
const int mod=998244353;
int fac[N+2],sz[N+2];
vector<int>adj[N+2];
int ans;
void dfs(int node,int par)
{
  int ch=0;sz[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);
    sz[node]+=sz[x];ch++;
  }
  ans=(1LL*ans*fac[ch])%mod;
  if(node==1)return;
  ans=(1LL*ans*(ch+1))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  fac[0]=1;
  for(int i=1;i<=N;i++)
    fac[i]=(1LL*fac[i-1]*i)%mod;
   ans=n;dfs(1,-1);cout<<ans<<endl;
   return 0;
}