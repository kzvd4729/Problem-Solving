/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/28/2020 20:39                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 202 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1374/problem/A
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int x,y,n;cin>>x>>y>>n;
    int ans=n-(n%x)+y;if(ans>n)ans-=x;
    cout<<ans<<endl;
  }
  return 0;
}