/****************************************************************************************
*  @author: kzvd4729                                         created: May/30/2021 15:21                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++17 (64)                          
*  run_time: 2500 ms                                         memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/840/problem/D
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
const int N=3e5,inf=1e9,mod=1000000007;
 int a[N+2];
vector<int>v[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i],v[a[i]].push_back(i);
   while(q--)
  {
    int l,r,k;cin>>l>>r>>k;
    int th=100,ans=inf;
    while(th--)
    {
      int x=a[l+rng()%(r-l+1)];
      int fr=upper_bound(v[x].begin(),v[x].end(),r)-lower_bound(v[x].begin(),v[x].end(),l);
      if(fr>(r-l+1)/k)ans=min(ans,x);
    }
    if(ans==inf)ans=-1;
    cout<<ans<<'\n';
  }
    return 0;
}