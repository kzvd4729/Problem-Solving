/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2020 21:24                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 7500 KB                              
*  problem: https://codeforces.com/contest/1383/problem/B
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
  int n;cin>>n;int xx=0;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];xx^=a[i];
  }
  if(xx==0){cout<<"DRAW\n";return ;}
  int b;
  for(int i=30;i>=0;i--)
  {
    if(xx&(1<<i)){b=i;break;}
  }
  int cnt=0;
  for(int i=1;i<=n;i++)if(a[i]&(1<<b))cnt++;
  if(cnt==1||(n-cnt)%2)cout<<"WIN\n";else cout<<"LOSE\n";
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