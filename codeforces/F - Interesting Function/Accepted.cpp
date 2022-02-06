/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/10/2021 20:50                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 62 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1538/problem/F
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
 long pw[N+2],vl[N+2];
long solve(long x)
{
  long n=x;
  vector<long>v;
  for(int i=0;i<=9;i++)
  {
    v.push_back(x%10);x/=10;
  }
   long ret=0;
  for(int i=9;i>=0;i--)
  {
    ret+=v[i]*vl[i];
  }
  return ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   pw[0]=1;vl[0]=1;
  for(int i=1;i<=11;i++)
  {
    pw[i]=pw[i-1]*10;
    vl[i]=pw[i]+vl[i-1];
  }
   //for(int i=0;i<=10;i++)cout<<pw[i]<<" ";cout<<endl;
  //for(int i=0;i<=10;i++)cout<<vl[i]<<" ";cout<<endl;
   int t;cin>>t;
  while(t--)
  {
    int l,r;cin>>l>>r;
    cout<<solve(r)-solve(l)<<endl;
  }
     return 0;
}