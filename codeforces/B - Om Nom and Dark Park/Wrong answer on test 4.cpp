/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/18/2020 11:39                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 11700 KB                             
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
  if(node==1)return ;
  int mn=min(aa[node*2],aa[node*2+1]);
  aa[node]+=mn;aa[node*2]-=mn,aa[node*2+1]-=mn;
}
int mx[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;m=(1<<(n+1))-1;
  for(int i=2;i<=m;i++)cin>>aa[i];
  dfs(1);int ans=0;
  //for(int i=2;i<=m;i++)cout<<aa[i]<<' ';cout<<endl;
  for(int i=2;i<=m;i++)
  {
    int p=31-__builtin_clz(i);
    mx[p]=max(mx[p],aa[i]);
  }
  for(int i=2;i<=m;i++)
  {
    int p=31-__builtin_clz(i);
    ans+=mx[p]-aa[i];
  }
  cout<<ans<<endl;
  return 0;
}