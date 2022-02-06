/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 10:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/884/problem/A
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
  int n,t;cin>>n>>t;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;x=86400-x;
    t-=x;if(t<=0)cout<<i<<endl,exit(0);
  }
   return 0;
}