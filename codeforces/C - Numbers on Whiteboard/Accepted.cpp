/****************************************************************************************
*  @author: kzvd4729#                                        created: Mar/24/2021 20:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 14300 KB                             
*  problem: https://codeforces.com/contest/1430/problem/C
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
 long a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
     multiset<int>st;
    for(int i=1;i<=n;i++)st.insert(i);
    cout<<2<<'\n';
    for(int i=1;i<n;i++)
    {
      int b,e;b=*st.rbegin();st.erase(st.find(b));
      e=*st.rbegin();st.erase(st.find(e));
      cout<<b<<" "<<e<<'\n';
       int tr=(b+e+1)/2;
      st.insert(tr);
    }
  }
  return 0;
}