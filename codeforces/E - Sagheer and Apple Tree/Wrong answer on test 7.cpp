/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/03/2020 18:37                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 234800 KB                            
*  problem: https://codeforces.com/contest/812/problem/E
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
#define long long long
using namespace std;
const int N=1e7;
int aa[N+2],a[N+2],b[N+2];
vector<int>adj[N+2];
int xx,cnt;
int dfs(int node)
{
  int f=1;
  for(auto x:adj[node])
    f=dfs(x);
  f^=1;
  if(!f)a[aa[node]]++,xx^=aa[node],cnt++;
  else b[aa[node]]++;
  return f;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=2;i<=n;i++)
  {
    int p;cin>>p;
    adj[p].push_back(i);
  }
  dfs(1);long ans=0;if(xx==0)ans=(1LL*cnt*(cnt+1))/2;//cout<<xx<<endl;
  for(int i=1;i<=N;i++)
  {
    if((xx^i)<=N)
      ans+=(1LL*a[i]*b[(xx^i)]);
  }
  cout<<ans<<endl;
  return 0;
}