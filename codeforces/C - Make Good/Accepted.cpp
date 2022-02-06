/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2020 16:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1270/problem/C
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
    int n;cin>>n;long sm=0,xx=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;sm+=x;xx^=x;
    }
    int l=0,c=0;long a=0,b=0;
    for(int i=0;i<55;i++)
    {
      int now=(bool)(sm&(1LL<<i));
      int r=(bool)(xx&(1LL<<i));
      now+=c;c=0;if(now==2)now=0,c=1;
      if(now!=l)
      {
        a|=(1LL<<i);if(now==1)c=1;
        r^=1;
      }
      l=r;
    }
    int now=(bool)(sm&(1LL<<55));
    if(now==0&&l==1)assert(0);
    if(now==1&&l==0)b=(1LL<<55);
    cout<<2<<"\n"<<a<<" "<<b<<"\n";
  }
  return 0;
}