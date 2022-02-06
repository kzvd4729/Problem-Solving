/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/15/2020 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 10900 KB                             
*  problem: https://codeforces.com/contest/1446/problem/A
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
const int N=1e6;
long a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,w;cin>>n>>w;long c=(w+1)/2;
    for(int i=1;i<=n;i++)cin>>a[i];
        int f=-1;
    for(int i=1;i<=n;i++)
    {
      if(a[i]>=c&&a[i]<=w)f=i;
    }
    if(f!=-1)
    {
      cout<<1<<" "<<f<<'\n';continue;
    }
    long sm=0;vector<long>v;
    for(int i=1;i<=n;i++)
    {
      if(a[i]<=w)sm+=a[i],v.push_back(i);
      if(sm>=c)break;
    }
    if(sm<c)cout<<-1<<'\n';
    else
    {
      cout<<(int)v.size()<<" ";
      for(auto x:v)cout<<x<<" ";
        cout<<'\n';
    }
  }
   return 0;
}