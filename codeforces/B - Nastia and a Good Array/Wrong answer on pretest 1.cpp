/****************************************************************************************
*  @author: * kzvd4729                                       created: May/07/2021 21:03                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++17 (64)                          
*  run_time: 30 ms                                           memory_used: 8100 KB                              
*  problem: https://codeforces.com/contest/1521/problem/B
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
 int a=1e9+7,b=1e9+9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
     if(n==1)
    {
      cout<<0<<'\n';continue;
    }
     vector<vector<int> >v;
     for(int i=1;i<n;i++)
    {
      if(i%2==0)
      {
        v.push_back({i,i+1,min(aa[i],aa[i+1]),a});
        aa[i+1]=min(aa[i],aa[i+1]);
        aa[i]=a;
      }
      else 
      {
        v.push_back({i,i+1,min(aa[i],aa[i+1]),b});
        aa[i+1]=min(aa[i],aa[i+1]);
        aa[i]=b;
      }
    }
    cout<<(int)v.size()<<'\n';
    for(auto x:v)
    {
      for(auto z:x)cout<<z<<" ";cout<<'\n';
    }
     //for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<endl;
  }
    return 0;
}