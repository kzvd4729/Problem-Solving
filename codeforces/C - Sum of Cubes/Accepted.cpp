/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/16/2021 20:48                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 77 ms                                           memory_used: 4600 KB                              
*  problem: https://codeforces.com/contest/1490/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int a[N+2];
map<long,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(long i=1;i<=10000;i++)mp[i*i*i]=1;
   int t;cin>>t;
  while(t--)
  {
    long x;cin>>x;
    int f=0;
    for(long i=1;i<=10000;i++)
    {
      if(mp.count(x-i*i*i))f=1;
    }
    if(f)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}