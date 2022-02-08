/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-15 00:38:07                      
*  solution_verdict: RE                                      language: C++ (GCC 9.2.1)                         
*  run_time: 331 ms                                          memory_used: 3768 KB                              
*  problem: https://atcoder.jp/contests/arc115/tasks/arc115_a
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
const int N=5000,inf=1e9,mod=998244353;
 string s[N+2];
 bool ck(int i)
{
  int un=0;
  for(int j=0;j<(int)s[i].size();j++)
    un+=(s[i][j]!=s[i+1][j]);
   return un%2;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
   for(int i=1;i<=n;i++)
  {
    cin>>s[i];
  }
   long ans=0;int od=0,ev=0;
  for(int i=n-1;i>=1;i--)
  {
    if(ck(i))
    {
      swap(od,ev);od++;
      ans+=od;
    }
    else
    {
      ev++;
      ans+=od;
    }
  }
  cout<<ans<<endl;
  return 0;
}