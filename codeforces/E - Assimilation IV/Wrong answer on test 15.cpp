/****************************************************************************************
*  @author: kzvd4729#                                        created: May/26/2021 16:18                        
*  solution_verdict: Wrong answer on test 15                 language: GNU C++17 (64)                          
*  run_time: 109 ms                                          memory_used: 4300 KB                              
*  problem: https://codeforces.com/contest/1525/problem/E
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
 int a[20+2][50000+2],n;
int howMany(int j)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(a[i][j]);
   sort(v.begin(),v.end());
  int ret=1;
  for(int i=n;i>=1;i--)
  {
    int id=upper_bound(v.begin(),v.end(),i)-v.begin();
    id=(int)v.size()-id;int c=id-(n-i);
        if(c<=0)return 0;
    ret=(1LL*ret*c)%mod;
  }
  return ret;
}
 int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int m;cin>>n>>m;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
   int fac=1;
  for(int i=1;i<=n;i++)fac=(1LL*fac*i)%mod;
   int ans=0;
  for(int j=1;j<=m;j++)
  {
    ans=(ans+fac-howMany(j));
    ans=(ans+mod)%mod;
  }
   cout<<(1LL*ans*big(fac,mod-2))%mod<<endl;
      return 0;
}