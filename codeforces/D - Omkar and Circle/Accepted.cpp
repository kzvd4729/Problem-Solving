/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/11/2020 22:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 27100 KB                             
*  problem: https://codeforces.com/contest/1372/problem/D
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
const int N=2e6;
int a[N+4];long qm[N+2];
int tt;
long ret(int id)
{
  return qm[id]-qm[id+(tt-2)*2];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   if(n==1)cout<<a[1]<<endl,exit(0);
  tt=n/2+1;
   for(int i=1;i<=n;i++)a[n+i]=a[i];
  for(int i=n+n;i>=1;i--)qm[i]=qm[i+2]+a[i];
   a[0]=a[n];long ans=0;
  for(int i=0;i<n;i++)
    ans=max(ans,a[i]+a[i+1]+ret(i+3));
  cout<<ans<<endl;
  return 0;
}