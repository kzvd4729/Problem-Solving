/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2020 11:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/800/problem/A
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#define long long long
using namespace std;
const int N=1e5;
int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,p;cin>>n>>p;long sm=0;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i],sm+=a[i];
  if(p>=sm)cout<<-1<<endl,exit(0);
    double lo=0,hi=1e18,md;int loop=100;
  while(loop--)
  {
    md=(lo+hi)/2.0;double sm=0;
    for(int i=1;i<=n;i++)
    {
      double rq=a[i]*md-b[i]*1.0;if(rq<0)continue;
      sm+=rq/(p*1.00);
    }
    if(sm>md)hi=md;else lo=md;
  }
  cout<<setprecision(6)<<fixed<<md<<endl;
  return 0;
}