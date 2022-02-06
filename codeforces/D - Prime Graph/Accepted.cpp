/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 23:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1178/problem/D
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
#define long long long
using namespace std;
const int N=1e6,mod=998244353;
bool isPrime(int x)
{
  for(int i=2;i<x;i++)if(x%i==0)return false;
  return true;
}
int vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;if(n==2)cout<<-1<<endl,exit(0);
   vector<pair<int,int> >v;
  for(int i=1;i<n;i++)v.push_back({i,i+1});
  v.push_back({1,n});
   int cnt=v.size();
  for(int i=1;i<=n;i++)
  {
    if(isPrime(cnt))break;
    if(vs[i])continue;
    v.push_back({i,i+2});vs[i+2]=1;cnt++;
    if(i+2>n)assert(0);
  }
  cout<<v.size()<<"\n";
  for(auto x:v)cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}