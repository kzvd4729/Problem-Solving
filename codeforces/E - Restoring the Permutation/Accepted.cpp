/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/25/2021 21:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 16100 KB                             
*  problem: https://codeforces.com/contest/1506/problem/E
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
const int N=1e6,inf=1e9,mod=998244353;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    vector<int>mn,mx;set<int>mxm,mnm;
    int pr=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      if(x!=pr)
      {
        mn.push_back(x);mx.push_back(x);
        for(int j=pr+1;j<x;j++)mnm.insert(j),mxm.insert(j);
        pr=x;
      }
      else
      {
        if((int)mnm.size()==0)assert(0);
         int b=*mnm.begin(),e=*mxm.rbegin();
        mn.push_back(b);mx.push_back(e);
         mnm.erase(b);mxm.erase(e);
      }
    }
    for(auto x:mn)cout<<x<<" ";cout<<endl;
    for(auto x:mx)cout<<x<<" ";cout<<endl;
  }
  return 0;
}