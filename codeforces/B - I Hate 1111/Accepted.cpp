/****************************************************************************************
*  @author: * kzvd4729                                       created: May/28/2021 20:23                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 39100 KB                             
*  problem: https://codeforces.com/contest/1526/problem/B
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
const int N=1e7,inf=1e9,mod=1000000007;
 int dp[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   dp[0]=1;
  for(int i=0;i<=1000000;i++)
  {
    dp[i+11]|=dp[i];
    dp[i+111]|=dp[i];
    dp[i+1111]|=dp[i];
    dp[i+1111]|=dp[i];
    dp[i+111111]|=dp[i];
    //dp[i+111111]|=dp[i];
     //if(dp[i]==0)cout<<i<<endl;
  }
   int t;cin>>t;
  while(t--)
  {
    int x;cin>>x;
    if(x>1000000)cout<<"YES\n";
    else if(dp[x])cout<<"YES\n";
    else cout<<"NO"<<'\n';
  }
      return 0;
}