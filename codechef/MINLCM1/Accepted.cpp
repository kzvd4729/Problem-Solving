/****************************************************************************************
*  @author: kzvd4729                                         created: 22-10-2021 13:04:15                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.17 sec                                        memory_used: 5.4M                                 
*  problem: https://www.codechef.com/SNCK1A21/problems/MINLCM1
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
const int N=1e6+10,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long x,k;cin>>x>>k;
    long mn=x*2;
    long mx=x*k*(x*k-1);
    cout<<mn<<" "<<mx<<endl;
  }
  return 0;
}