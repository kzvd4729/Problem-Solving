/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/29/2020 21:45                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1389/problem/D
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
const long N=1e6;
long solve()
{
  long n,k;cin>>n>>k;
  long a,b,c,d;cin>>a>>b>>c>>d;
   long free=max(0LL,min(b,d)-max(a,c));
    if(k<=free*n)return 0;k-=free*n;
   long ex=0;if(b<c)ex=c-b;if(d<a)ex=a-d;
  long mx=max(b,d)-min(a,c)-free;
   if(k<=mx)return ex+k;
  long ans=ex+mx+(k-mx)*2;
   long m=min(k/mx,n);
  long now=(ex+mx)*m;
  k-=mx*m;
  if(m==n)now+=k*2;
  else now+=min(k*2,ex+k);
   ans=min(ans,now);
   return ans;
 }
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    cout<<solve()<<'\n';
  }
  return 0;
}