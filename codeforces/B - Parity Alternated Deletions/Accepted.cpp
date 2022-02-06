/****************************************************************************************
*  @author: kzvd4729                                         created: May/25/2020 10:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1144/problem/B
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
int aa[N+1],bb[N+2],a,b;
int ans(int a,int b)
{
  int ret=0;
  for(int i=1;i<=a;i++)ret+=aa[i];
  for(int i=1;i<=b;i++)ret+=bb[i];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int sm=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;sm+=x;
    if(x%2==0)aa[++a]=x;
    else bb[++b]=x;
  }
  sort(aa+1,aa+a+1,greater<int>());sort(bb+1,bb+b+1,greater<int>());
  if(a==b)cout<<0<<endl,exit(0);
  if(a<b)cout<<sm-ans(a,a+1)<<endl;
  else cout<<sm-ans(b+1,b)<<endl;
   return 0;
}