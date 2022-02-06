/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/29/2020 21:32                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3600 KB                              
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
    if(k<=1LL*free*n)return 0;
   long ex=0;if(b<c)ex=c-b;if(d<a)ex=d-a;
  long mx=max(b,d)-min(a,c);
   if(k<=mx)return ex+k-free;
  long ans=ex+mx-free+(k-mx)*2LL;
   long m=min(k/mx,n);
  long now=(ex+mx-free)*m;
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