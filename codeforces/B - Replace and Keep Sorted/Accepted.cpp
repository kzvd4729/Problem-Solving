/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/02/2021 21:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1485/problem/B
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 #pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
  int a[N+2],b[N+2];
long sm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,q,k;cin>>n>>q>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=2;i<n;i++)b[i]=a[i+1]-a[i-1]-1-1;
   for(int i=1;i<=n;i++)sm[i]=sm[i-1]+b[i];
   while(q--)
  {
    int l,r;cin>>l>>r;
    if(l==r)
    {
      cout<<k-1<<'\n';continue;
    }
    long ans=sm[r-1]-sm[l];
    ans+=a[l+1]-1-1;
    ans+=k-a[r-1]-1;
    cout<<ans<<'\n';
  }
  return 0;
}