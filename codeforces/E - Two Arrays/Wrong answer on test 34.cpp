/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/11/2020 22:31                        
*  solution_verdict: Wrong answer on test 34                 language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1366/problem/E
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
const int N=5e5,mod=998244353;
int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=m;i++)cin>>b[i];
   long ans=1;int p=m,l=-1;
  for(int i=n;i>=1;i--)
  {
    if(a[i]==b[p]&&l==-1)l=i;
    else if(a[i]<b[p])
    {
      if(l==-1)cout<<0<<endl,exit(0);
      ans=(ans*1LL*(l-i))%mod;p--,l=-1;
      if(p==0)cout<<0<<endl,exit(0);
      i++;
    }
  }
  //cout<<l<<endl;
  if(l==-1)cout<<0<<endl,exit(0);
  //ans=(ans*1LL*(l))%mod;
  cout<<ans<<endl;
  return 0;
}