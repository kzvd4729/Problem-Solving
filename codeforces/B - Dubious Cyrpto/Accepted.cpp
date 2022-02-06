/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/19/2020 15:35                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1379/problem/B
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
void solve()
{
  long l,r,m;cin>>l>>r>>m;
  long df=r-l;
  for(long a=l;a<=r;a++)
  {
    long n=m/a;
     if(m-a*n<=df&&n)
    {
      long ad=m-a*n;
      cout<<a<<" "<<l+ad<<" "<<l<<endl;
      return;
    }
    n++;
    if(a*n-m<=df)
    {
      long ad=a*n-m;
      cout<<a<<" "<<l<<" "<<l+ad<<endl;
      return;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}