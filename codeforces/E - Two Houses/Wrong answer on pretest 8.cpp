/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/29/2021 22:01                        
*  solution_verdict: Wrong answer on pretest 8               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1498/problem/E
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
  int out[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    out[i]=n-1-x;
  }
   vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)v.push_back({out[i],i});
   sort(v.begin(),v.end());
   while(n)
  {
    if(v.back().first==n-1)
    {
      v.pop_back();n--;continue;
    }
    if(n==0)break;
     if(v[0].first==0)
    {
      for(int i=1;i<n;i++)v[i].first--;
      v.erase(v.begin());n--;
      continue;
    }
    break;
  }
  if(n==0)cout<<"! 0 0"<<endl;
  else cout<<"! "<<v[0].second<<" "<<v.back().second<<endl;
   return 0;
}