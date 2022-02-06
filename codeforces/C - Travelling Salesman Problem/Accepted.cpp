/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2021 21:51                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 77 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1503/problem/C
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
const int N=1e6,inf=1e9,mod=1e9+7;
 pair<int,int>p[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>p[i].first>>p[i].second;
  sort(p+1,p+n+1);
     int mx=p[1].first+p[1].second;
  long ans=0;
  for(int i=2;i<=n;i++)
  {
    if(p[i].first>mx)ans+=(p[i].first-mx);
    mx=max(mx,p[i].first+p[i].second);
  }
  for(int i=1;i<=n;i++)ans+=p[i].second;
    cout<<ans<<endl;
   return 0;
}