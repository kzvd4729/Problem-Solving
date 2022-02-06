/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/23/2020 16:52                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/1280/problem/A
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
const long N=1e6;
const long mod=1e9+7;
string s;long x;long sz;
void add(long l,long r,long t)
{
  sz=(sz+(r-l+1)*t)%mod;
  if(s.size()>=x)return ;
  while(t--)
  {
    for(long i=l;i<=r;i++)s.push_back(s[i]);
  }
}
void solve()
{
  cin>>x>>s;sz=s.size();
  for(long i=0;i<x;i++)add(i+1,sz-1,s[i]-'0'-1);
  cout<<(sz+mod)%mod<<"\n";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}