/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/02/2020 18:19                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1363/problem/C
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
int dg[N+2];
void solve()
{
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)dg[i]=0;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;dg[u]++,dg[v]++;
  }
  if(dg[m]==1||n%2==0)cout<<"Ayush\n";
  else cout<<"Ashish\n";
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