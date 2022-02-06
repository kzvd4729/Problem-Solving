/****************************************************************************************
*  @author: kzvd4729#                                        created: May/29/2020 20:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/439/problem/B
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
  int n,d;cin>>n>>d;
  for(int i=1;i<=n;i++)cin>>aa[i];
   sort(aa+1,aa+n+1);
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    ans+=1LL*aa[i]*d;
    d--;if(d==0)d=1;
  }
  cout<<ans<<endl;
   return 0;
}