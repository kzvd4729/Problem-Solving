/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2020 20:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/911/problem/D
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
const int N=2e5;
int a[N+2];
void pr(int x)
{
  if(x)cout<<"odd\n";
  else cout<<"even\n";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   int cnt=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<i;j++)cnt+=(a[j]>a[i]);
  }
  cnt%=2;int q;cin>>q;
  while(q--)
  {
    int l,r;cin>>l>>r;
    int df=(r-l+1);df=(df*(df-1))/2;
    df%=2;cnt^=df;
    pr(cnt);
  }
  return 0;
}