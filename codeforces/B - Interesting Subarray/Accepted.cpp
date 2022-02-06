/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2020 14:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1270/problem/B
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
int a[N+2];
void solve()
{
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=2;i<=n;i++)
  {
    if(abs(a[i]-a[i-1])>1){cout<<"YES\n"<<i-1<<" "<<i<<"\n";return;}
  }
  cout<<"NO\n";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}