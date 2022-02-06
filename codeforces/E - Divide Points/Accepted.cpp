/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/29/2021 01:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7900 KB                              
*  problem: https://codeforces.com/contest/1270/problem/E
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
 int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
   for(int i=2;i<=n;i++)a[i]-=a[1],b[i]-=b[1];
  a[1]=0,b[1]=0;
     vector<int>v;int p=2;
  while(true)
  {
    for(int i=1;i<=n;i++)
    {
      if((a[i]+b[i])%p==0)v.push_back(i);
    }
    if((int)v.size()<n)break;
     v.clear();
    for(int i=1;i<=n;i++)
    {
      if(a[i]%p==0)v.push_back(i);
    }
    if((int)v.size()<n)break;
     v.clear();p*=2;
  }
  cout<<(int)v.size()<<endl;
  for(auto x:v)cout<<x<<" ";cout<<endl;
  return 0;
}