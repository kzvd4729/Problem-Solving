/****************************************************************************************
*  @author: kzvd4729                                         created: May/27/2020 22:00                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/1358/problem/E
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
int aa[N+2];long qm[N+2],mn[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long sm=0;
  for(int i=1;i<=(n+1)/2;i++)cin>>aa[i],sm+=aa[i];
   int x;cin>>x;
  for(int i=1;i<=n/2;i++)
  {
    qm[i]=qm[i-1]+x-aa[i];
    mn[i]=(mn[i-1],qm[i]);
  }
  int id=n/2;
  for(int i=(n+1)/2;i<=n;i++)
  {
    if(sm+mn[id]>0)cout<<i<<endl,exit(0);
    id--,sm+=x;
  }
  cout<<-1<<endl;
  return 0;
}