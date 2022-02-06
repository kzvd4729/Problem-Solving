/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/18/2020 11:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 8100 KB                              
*  problem: https://codeforces.com/contest/526/problem/B
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
int m,aa[N+2],dp[N+2];
void dfs(int node)
{
  if(node>m)return ;
  dfs(node*2);dfs(node*2+1);
   dp[node]=max(dp[node*2]+aa[node*2],dp[node*2+1]+aa[node*2+1]);
}
int ans,mx;
void dds(int node,int ad)
{
  if(node>m)return;
   int now=mx-(dp[node]+ad);
  ans+=now;dds(node*2,ad+now+aa[node*2]),dds(node*2+1,ad+now+aa[node*2+1]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;m=(1<<(n+1))-1;
  for(int i=2;i<=m;i++)cin>>aa[i];
  dfs(1);mx=dp[1];dds(1,0);cout<<ans<<endl;
  return 0;
}