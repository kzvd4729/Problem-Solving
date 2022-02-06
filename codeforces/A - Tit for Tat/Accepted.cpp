/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/21/2021 19:38                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1516/problem/A
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int a[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
     for(int i=1;i<n;i++)
    {
      if(k==0)continue;
       if(a[i]>k)
      {
        a[i]-=k;a[n]+=k;
        k=0;
      }
      else 
      {
        k-=a[i];a[n]+=a[i];
        a[i]=0;
      }
    }
     for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  }
  return 0;
}