/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2021 15:22                        
*  solution_verdict: Wrong answer on pretest 5               language: GNU C++17 (64)                          
*  run_time: 124 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1500/problem/A
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
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   n=min(n,100);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j)continue;
      for(int k=1;k<=n;k++)
      {
        if(i==k||j==k)continue;
        for(int l=1;l<=n;l++)
        {
          if(i==l||j==l||k==l)continue;
          if(a[i]+a[j]==a[k]+a[l])
          {
            cout<<"YES"<<endl;
            cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl,exit(0);
          }
        }
      }
    }
  }
  cout<<"NO"<<endl;
    return 0;
}