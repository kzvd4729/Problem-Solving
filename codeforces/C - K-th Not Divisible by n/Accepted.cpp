/****************************************************************************************
*  @author: * kzvd4729                                       created: May/09/2020 20:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1352/problem/C
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
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,k;cin>>n>>k;
    long lo=0,hi=2e9+100,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(md-(md/n)>=k)hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      if(md-(md/n)>=k)break;
    }
    cout<<md<<"\n";
  }
    return 0;
}