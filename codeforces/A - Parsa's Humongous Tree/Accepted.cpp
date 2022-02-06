/****************************************************************************************
*  @author: kzvd4729#                                        created: May/27/2021 19:30                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 217 ms                                          memory_used: 34200 KB                             
*  problem: https://codeforces.com/contest/1528/problem/A
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
const int N=1e6,inf=1e9,mod=1000000007;
 int l[N+2],r[N+2];
vector<int>ad[N+2];
 pair<long,long>dfs(int nd,int pr)
{
  pair<long,long>ret={0,0};
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    pair<long,long>p=dfs(x,nd);
     ret.first+=max(abs(l[nd]-l[x])+p.first,abs(l[nd]-r[x])+p.second);
    ret.second+=max(abs(r[nd]-l[x])+p.first,abs(r[nd]-r[x])+p.second);
  }
  return ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
    for(int i=1;i<=n;i++)ad[i].clear();
     for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
    pair<long,long>p=dfs(1,-1);
    cout<<max(p.first,p.second)<<endl;
  }
     return 0;
}