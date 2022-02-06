/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/20/2020 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1370/problem/B
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<int>a,b;
    for(int i=1;i<=n+n;i++)
    {
      int x;cin>>x;
      if(x%2==0)a.push_back(i);
      else b.push_back(i);
    }
    for(int i=1;i<n;i++)
    {
      if(a.size()>=2)
      {
        cout<<a.back();a.pop_back();
        cout<<" "<<a.back();a.pop_back();
      }
      else
      {
        cout<<b.back();b.pop_back();
        cout<<" "<<b.back();b.pop_back();
      }
      cout<<"\n";
    }
  }
  return 0;
}