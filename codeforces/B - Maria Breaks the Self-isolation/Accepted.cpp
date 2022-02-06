/****************************************************************************************
*  @author: kzvd4729                                         created: May/27/2020 19:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1358/problem/B
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
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    sort(aa+1,aa+n+1);
     int ans=0;
    for(int i=1;i<=n;i++)
    {
      if(i>=aa[i])ans=i;
    }
    cout<<ans+1<<endl;
  }
  return 0;
}