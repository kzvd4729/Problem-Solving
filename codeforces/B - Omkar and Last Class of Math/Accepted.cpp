/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/11/2020 21:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1372/problem/B
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int sq=sqrt(n+1);
    long lcm=n;long pa=n,pb=0;
    for(int i=1;i<=sq;i++)
    {
      if(n%i)continue;
       int a=n/i;int b=n-a;
      if(a&&b)
      {
        if((1LL*a*b)/__gcd(a,b)<lcm)lcm=(1LL*a*b)/(__gcd(a,b)),pa=a,pb=b;
      }
      a=i;b=n-a;
      if(a&&b)
      {
        if((1LL*a*b)/__gcd(a,b)<lcm)lcm=(1LL*a*b)/(__gcd(a,b)),pa=a,pb=b;
      }
    }
    cout<<pa<<" "<<pb<<endl;
  }
  return 0;
}