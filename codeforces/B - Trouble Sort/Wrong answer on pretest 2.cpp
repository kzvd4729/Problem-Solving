/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/07/2020 20:55                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4100 KB                              
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
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    vector<int>a,b;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      if(x)a.push_back(aa[i]);
      else b.push_back(aa[i]);
    }
    int f=0;
    for(int i=1;i<a.size();i++)if(a[i]<a[i-1])f=1;
    for(int i=1;i<b.size();i++)if(b[i]<b[i-1])f=1;
    if(f)cout<<"No\n";else cout<<"Yes\n";
  }
   return 0;
}