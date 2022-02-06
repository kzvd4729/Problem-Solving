/****************************************************************************************
*  @author: kzvd4729#                                        created: Mar/24/2021 19:57                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1430/problem/B
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
const int N=1e6,inf=1e9,mod=998244353;
 long a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
     long ans=0;
    for(int i=1;i<=n;i++)
    {
      long now=a[i];
      if(i-k-1>=0)now-=a[i-k-1];
       ans=max(ans,now);
    }
    cout<<ans<<endl;
  }
  return 0;
}