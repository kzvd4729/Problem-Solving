/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/04/2020 19:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1453/problem/B
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
const int N=1e6;
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=2)
    {
      cout<<0<<endl;continue;
    }
    long tt=0;
    for(int i=2;i<=n;i++)tt+=abs(a[i]-a[i-1]);
     long ans=min(tt-abs(a[1]-a[2]),tt-abs(a[n]-a[n-1]));
    for(int i=2;i<n;i++)
    {
      long now=tt;
      now-=abs(a[i]-a[i-1]);now-=abs(a[i]-a[i+1]);
      now+=abs(a[i-1]-a[i+1]);
      ans=min(ans,now);
    }
    cout<<ans<<endl;
  }
  return 0;
}