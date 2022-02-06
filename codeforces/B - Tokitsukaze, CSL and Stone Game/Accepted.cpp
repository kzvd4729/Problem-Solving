/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/21/2020 17:26                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1190/problem/B
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
int a[N+2];
void p1()
{
  cout<<"cslnb"<<endl,exit(0);
}
void p2()
{
  cout<<"sjfnb"<<endl,exit(0);
}
void ck(int n)
{
  for(int i=1;i<n;i++)
  {
    if(a[i]==a[i-1])p1();
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
   sort(a,a+n);
    if(n>=2&&a[0]==a[1]&&a[0]==0)p1();
  for(int i=0;i<n-1;i++)
  {
    if(a[i]!=a[i+1])continue;
    a[i]--;ck(n);
     a[i]++;break;
  }
   long ad=0;
  for(int i=0;i<n;i++)ad+=a[i]-i;
   if(ad%2==0)p1();else p2();
   return 0;
}