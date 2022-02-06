/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 21:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1359/problem/D
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int ans=0;
  for(int j=-30;j<=30;j++)
  {
    int now=0;
    for(int i=1;i<=n;i++)
    {
      int x=aa[i];if(x>j)x=-1e9;
      now+=x;
      ans=max(ans,now-j);if(now<0)now=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}