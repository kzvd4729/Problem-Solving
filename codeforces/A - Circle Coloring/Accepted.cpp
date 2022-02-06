/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2020 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1408/problem/A
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
const int N=1e6;
int a[N+2],b[N+2],c[N+2],d[N+2];
bool ok(int n)
{
  for(int i=2;i<=n;i++)if(d[i]==d[i-1])return false;
  return d[1]!=d[n];
}
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)cin>>c[i];
     d[1]=a[1];
    for(int i=2;i<=n;i++)
    {
      if(a[i]!=d[i-1])d[i]=a[i];
      else d[i]=b[i];
    }
    while(true)
    {
      d[n]=a[n];if(ok(n))break;
      d[n]=b[n];if(ok(n))break;
      d[n]=c[n];if(ok(n))break;
            d[1]=a[1];if(ok(n))break;
      d[1]=b[1];if(ok(n))break;
      d[1]=c[1];if(ok(n))break;
    }
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
      cout<<'\n';
  }
   return 0;
}