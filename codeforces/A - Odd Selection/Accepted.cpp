/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/02/2020 17:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1363/problem/A
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
#define long long long
using namespace std;
const int N=1e6;
void solve()
{
  int n,k;cin>>n>>k;int od=0,ev=0,sm=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;sm+=x;
    if(x%2==0)ev++;else od++;
  }
  if(od==0)cout<<"No\n";
  else if(k==n&&sm%2==0)cout<<"No\n";
  else if(od==n&&k%2==0)cout<<"No\n";
  else cout<<"Yes\n"; 
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