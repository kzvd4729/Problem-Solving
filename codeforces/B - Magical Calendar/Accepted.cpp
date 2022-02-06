/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/01/2020 20:05                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1371/problem/B
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
long sm(long x)
{
  return x*(x+1)/2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,r;cin>>n>>r;
    if(r<n)cout<<sm(r)<<endl;
    else 
    {
      //cout<<n-1<<" "<<r-n<<endl;
      cout<<sm(n-1)+1<<endl;
    }
  }
  return 0;
}