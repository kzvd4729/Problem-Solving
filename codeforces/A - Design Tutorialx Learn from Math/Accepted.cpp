/****************************************************************************************
*  @author: kzvd4729                                         created: May/24/2020 16:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/472/problem/A
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
int vis[N+2];
void seive()
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i+i;j<=N;j+=i)vis[j]=1;
  }
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();int n;cin>>n;
  while(true)
  {
    int a=1+rng()%(n-1);
    if(vis[a]&&vis[n-a])cout<<a<<" "<<n-a<<endl,exit(0);
  }
   return 0;
}