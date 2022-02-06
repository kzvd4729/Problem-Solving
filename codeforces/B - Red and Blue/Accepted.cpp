/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/18/2021 12:37                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1469/problem/B
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
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int mx=0,sm=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      sm+=x;mx=max(mx,sm);
    }
     int ans=mx;//cout<<mx<<endl;
     cin>>n;mx=0,sm=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      sm+=x;mx=max(mx,sm);
    }
     cout<<ans+mx<<endl;
  }  
     return 0;
}