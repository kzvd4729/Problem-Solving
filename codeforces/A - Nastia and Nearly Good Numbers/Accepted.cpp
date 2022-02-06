/****************************************************************************************
*  @author: * kzvd4729                                       created: May/07/2021 20:47                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 92 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1521/problem/A
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
    int a,b;cin>>a>>b;
     if(b==1)
    {
      cout<<"NO"<<endl;
      continue;
    }
     long i=2*b-1,j=1;
     long x=i*a,y=j*a;
     cout<<"YES"<<endl;
    cout<<x<<" "<<y<<" "<<x+y<<endl;
  }
       return 0;
}