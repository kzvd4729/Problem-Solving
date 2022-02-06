/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/06/2021 20:08                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1493/problem/A
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
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
     int sm=0;
    vector<int>v;
    for(int i=1;i<=k;i++)
    {
      sm+=i;
      if(sm>=k)break;
      v.push_back(i);
    }
    for(int i=k+1;i<=n;i++)v.push_back(i);
    cout<<v.size()<<endl;
    for(auto x:v)cout<<x<<" ";
      cout<<endl;
  }
       return 0;
}