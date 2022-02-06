/****************************************************************************************
*  @author: kzvd4729#                                        created: May/29/2020 20:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/439/problem/A
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
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,d;cin>>n>>d;int sm=0;
  for(int i=1;i<=n;i++)cin>>aa[i],sm+=aa[i];
   if(sm+(n-1)*10>d)cout<<-1<<endl,exit(0);
    d-=sm;cout<<d/5<<endl;
   return 0;
}