/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/08/2021 20:55                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 1200 ms                                         memory_used: 140900 KB                            
*  problem: https://codeforces.com/gym/102966/problem/E
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long N=1e6,inf=1e9,mod=1e9+7;
 long fx[N+2],up[N+2],sub[N+2];
vector<long>ad[N+2];
void dfs(long nd)
{
  for(auto x:ad[nd])
  {
    dfs(x);up[nd]+=up[x];
  }
}
void dfs2(long nd)
{
  sub[nd]=up[nd]+fx[nd];
  for(auto x:ad[nd])
  {
    dfs2(x);sub[nd]+=sub[x];
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,q;cin>>n>>m>>q;
   long rt;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;
    if(x==0)rt=i;
    else ad[x].push_back(i);
  }
   for(long i=1;i<=m;i++)
  {
    long ty,e,v;cin>>ty>>e>>v;
    if(ty==1)fx[e]+=v;
    else up[e]+=v;
  }
   dfs(rt);dfs2(rt);
   for(long i=1;i<=q;i++)
  {
    long ty,e;cin>>ty>>e;
    if(ty==1)cout<<up[e]+fx[e]<<'\n';
    else cout<<sub[e]<<'\n';
  }
    return 0;
}