/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2021 22:55                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 600 KB                               
*  problem: https://codeforces.com/contest/1268/problem/B
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
const int N=3e5,inf=1e9,mod=998244353;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;vector<int>v;long tt=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;tt+=x;
     if((int)v.size()==0)
    {
      if(x%2)v.push_back(x);
    }
    else
    {
      if(x%2==0)
      {
        if(v.back()%2==0);
        else v.push_back(x);
      }
      else
      {
        if(v.back()%2==0)v.push_back(x);
        else v.pop_back();
      }
    }
  }
  n=v.size();int ws=(n+1)/2;
   cout<<(tt-ws)/2<<endl;
   return 0;
}