/****************************************************************************************
*  @author: kzvd4729#                                        created: May/26/2021 14:39                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1525/problem/B
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
const int N=1e6,inf=1e9,mod=998244353;
 int a[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
      int f=1;
    for(int i=1;i<=n;i++)if(a[i]!=i)f=0;
     if(f==1){cout<<0<<endl;continue;}
     if(a[1]==1 || a[n]==n){cout<<1<<endl;continue;}
    if(a[1]==n && a[n]==1){cout<<3<<endl;continue;}
    cout<<2<<endl;
    }
       return 0;
}