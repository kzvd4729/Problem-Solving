/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/25/2021 21:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1506/problem/F
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=998244353;
 pair<int,int>p[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i].first;
    for(int i=1;i<=n;i++)cin>>p[i].second;
     sort(p+1,p+n+1);p[0]={1,1};
     long ans=0;
    for(int i=1;i<=n;i++)
    {
      int a=p[i].first-p[i-1].first+1,b=p[i].second-p[i-1].second+1;
       if((p[i-1].first+p[i-1].second)%2==0)
      {
        if(a==b)ans+=a-1;
        else ans+=(a-b)/2;
      }
      else
      {
        ans+=(a-b+1)/2;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}