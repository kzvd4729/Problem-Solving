/****************************************************************************************
*  @author: * kzvd4729                                       created: May/16/2020 17:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1355/problem/A
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
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2];
long ret(long n)
{
  long mn=10,mx=0;
  while(n)
  {
    mn=min(mn,n%10);mx=max(mx,n%10);
    n/=10;
  }
  return mn*mx;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,k;cin>>n>>k;
    for(int i=2;i<=k;i++)
    {
      long add=ret(n);if(add==0)break;
      n+=add;
    }
    cout<<n<<"\n";
  }
  return 0;
}