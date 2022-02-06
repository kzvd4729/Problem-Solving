/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/12/2021 02:32                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 701 ms                                          memory_used: 49000 KB                             
*  problem: https://codeforces.com/contest/1322/problem/C
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
const int N=5e5,inf=1e9,mod=1e9+7;
 long a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
        vector<vector<int> >ad(n+2);
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      ad[v].push_back(u);
    }
    for(int i=1;i<=n;i++)sort(ad[i].begin(),ad[i].end());
     map<vector<int>,long>mp;
    for(int i=1;i<=n;i++)
    {
      if((int)ad[i].size()==0)continue;
      mp[ad[i]]+=a[i];
    }
    long ans=0;
    for(auto x:mp)ans=__gcd(ans,x.second);
    cout<<ans<<'\n';
  }
  return 0;
}