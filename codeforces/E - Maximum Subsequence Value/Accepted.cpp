/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/07/2020 22:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1365/problem/E
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
const int N=500;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long ans=0;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      for(int k=1;k<=n;k++)
        ans=max(ans,(aa[i]|aa[j]|aa[k]));
    }
  }
  cout<<ans<<endl;
  return 0;
}