/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/07/2020 22:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1365/problem/B
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
int aa[N+2],ty[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)cin>>ty[i];
     int a=0,b=0;
    for(int i=1;i<=n;i++)
    {
      if(ty[i]==0)a=1;
      else b=1;
    }
    if(a&&b)
    {
      cout<<"Yes\n";continue;
    }
    int f=0;
    for(int i=2;i<=n;i++)
      if(aa[i]<aa[i-1])f=1;
    if(f)cout<<"No\n";else cout<<"Yes\n";
  }
   return 0;
}