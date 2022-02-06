/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/03/2021 14:32                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1551/problem/D1
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
 void no()
{
  cout<<"NO"<<endl;
}
void ya()
{
  cout<<"YES"<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m,h;cin>>n>>m>>h;
     if(m%2)
    {
      swap(n,m);
      h=(n*m)/2-h;
    }
     if(n%2==0 && m%2==0)
    {
      if(h%2==0)ya();
      else no();
    }
    else if(m%2==0)
    {
      if(h==0)no();
      else
      {
        int tt=n*m/2;
        if((tt-h)%2==0)ya();
        else no();
      }
    }
  }
  return 0;
}