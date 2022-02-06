/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/01/2020 20:57                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 93 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1371/problem/E2
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
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
int n,p,a[N+2];
bool ck(int md)
{
  for(int j=1;j<=n;j++)
  {
    int id=upper_bound(a+1,a+n+1,md+j-1)-a;
    //cout<<"*"<<id-j<<endl;
    if(id-j>=p)return false;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>p;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);int mn=a[1];
    int cr=mn;
  for(int i=1;i<=n;i++)
  {
    if(cr>=a[i])cr++;
    else {mn+=a[i]-cr;cr=a[i]+1;}
  }
  int lo=mn,hi=1e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ck(md))lo=md;else hi=md;
  }
  for(md=hi;md>=lo;md--)if(ck(md))break;
  cout<<md-mn+1<<endl;
  for(int i=mn;i<=md;i++)cout<<i<<" ";cout<<endl;
  return 0;
}