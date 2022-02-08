/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2021 12:50:37                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/APRIL21A/problems/SDICE
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    int m=n%4;
    long ans=0;
    if(m==1)ans=21-1;
    else if(m==2)ans=21*2-1-1-2-2;
    else if(m==3)ans=21*3-1-1-1-2-2-3-2;
    n-=m;
    if(n)
    {
      ans+=(n-1)*(6+5)+(4-m)*(6+5+4);
    }
    cout<<ans<<endl;
  }
  return 0;
}