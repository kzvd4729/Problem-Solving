/****************************************************************************************
*  @author: kzvd4729#                                        created: Sep/25/2020 14:22                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 483 ms                                          memory_used: 16300 KB                             
*  problem: https://codeforces.com/contest/1420/problem/D
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
const int mod=998244353;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int fac[N+2];
void init()
{
  fac[0]=1;
  for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int ncr(int n,int r)
{
  int ret=(1LL*fac[n]*big(fac[r],mod-2))%mod;
  return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();int n,k;cin>>n>>k;
  vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)
  {
    int l,r;cin>>l>>r;
    v.push_back({l,0});v.push_back({r,1});
  }
  sort(v.begin(),v.end());
  int cnt=0;long ans=0;
  for(auto x:v)
  {
    if(x.second)cnt--;
    else
    {
      cnt++;
      if(cnt>=k)ans=(ans+ncr(cnt-1,k-1))%mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}