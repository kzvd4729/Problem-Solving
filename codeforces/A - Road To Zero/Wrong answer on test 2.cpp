/****************************************************************************************
*  @author: kzvd4729                                         created: May/24/2020 10:23                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1342/problem/A
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
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int x,y;cin>>x>>y;int a,b;cin>>a>>b;
    if(a>b)swap(a,b);
    long ans=1LL*x*(b-a)+1LL*y*a;cout<<ans<<endl;
  }
    return 0;
}