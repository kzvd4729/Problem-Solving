/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2020 00:11                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 233 ms                                          memory_used: 15600 KB                             
*  problem: https://codeforces.com/contest/1266/problem/E
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
int a[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long sm=0;
  for(int i=1;i<=n;i++)cin>>a[i],sm+=a[i];
   int q;cin>>q;map<pair<int,int>,int>mp;
  int ed=0;
  while(q--)
  {
    int x,y,z;cin>>x>>y>>z;
        if(mp[{x,y}])
    {
      int d=mp[{x,y}];
      cnt[d]--;if(cnt[d]<a[d])ed--;
      mp[{x,y}]=0;
    }
    if(z)
    {
      mp[{x,y}]=z;
      cnt[z]++;if(cnt[z]<=a[z])ed++;
    }
    cout<<sm-ed<<'\n';
  }
  return 0;
}