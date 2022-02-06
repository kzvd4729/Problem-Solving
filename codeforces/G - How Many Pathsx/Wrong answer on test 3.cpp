/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/07/2021 23:32                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 15200 KB                             
*  problem: https://codeforces.com/contest/1547/problem/G
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
 const int N=4e5,inf=1e9;
 vector<int>ad[N+2];
int cnt[N+2];
 void dfs(int nd)
{
  if(cnt[nd]==3)return ;
  cnt[nd]++;
   for(auto x:ad[nd])dfs(x);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
     for(int i=1;i<=n;i++)ad[i].clear(),cnt[i]=0;
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);
    }
    dfs(1);
     for(int i=1;i<=n;i++)
    {
      if(cnt[i]==3)cnt[i]=-1;
      cout<<cnt[i]<<" ";
    }
    cout<<endl;
  }
    return 0;
}