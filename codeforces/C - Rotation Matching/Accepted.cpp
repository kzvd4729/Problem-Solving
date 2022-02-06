/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/07/2020 21:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 607 ms                                          memory_used: 22800 KB                             
*  problem: https://codeforces.com/contest/1365/problem/C
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
int po[N+2];
int solve(vector<int>a,vector<int>b)
{
  int sz=b.size();
  for(int i=0;i<sz;i++)b.push_back(b[i]);
   map<int,int>mp;
  for(int i=0;i<a.size();i++)po[a[i]]=i;
  int ret=0;
  for(int i=0;i<b.size();i++)
  {
    if(i>=sz)--mp[po[b[i-sz]]-(i-sz)];
    int now=++mp[po[b[i]]-i];
    ret=max(ret,now);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>a(n),b(n);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
   cout<<max(solve(a,b),solve(b,a))<<endl;
   return 0;
}