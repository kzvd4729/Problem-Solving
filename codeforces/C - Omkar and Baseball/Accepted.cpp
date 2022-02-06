/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/11/2020 21:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 9100 KB                              
*  problem: https://codeforces.com/contest/1372/problem/C
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
int a[N+2];
void solve()
{
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   vector<int>v;
  for(int i=1;i<=n;i++)
    if(i!=a[i])v.push_back(i);
  if(v.size()==0)
  {
    cout<<0<<endl;return;
  }
  sort(v.begin(),v.end());
  if(v.back()-v[0]+1==v.size())
  {
    cout<<1<<endl;return;
  }
  cout<<2<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}