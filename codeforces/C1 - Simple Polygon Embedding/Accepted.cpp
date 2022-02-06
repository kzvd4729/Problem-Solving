/****************************************************************************************
*  @author: kzvd4729                                         created: May/23/2020 12:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1354/problem/C1
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
#define long long long
using namespace std;
const int N=2e5;
const double pi=acos(-1.0);
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    double n;cin>>n;n*=2;
    double ans=1.0/(2.0*tan(pi/n));
    cout<<setprecision(6)<<fixed<<ans*2<<endl;
  }
  return 0;
}