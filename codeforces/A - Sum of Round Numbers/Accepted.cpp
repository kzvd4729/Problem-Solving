/****************************************************************************************
*  @author: * kzvd4729                                       created: May/09/2020 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/1352/problem/A
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
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<int>v,u;
    int p=1;
    while(n)
    {
      if(n%10)v.push_back(p*(n%10));
      n/=10;p*=10;
    }
    cout<<v.size()<<"\n";
    for(auto x:v)cout<<x<<" ";cout<<"\n";
  }
  return 0;
}