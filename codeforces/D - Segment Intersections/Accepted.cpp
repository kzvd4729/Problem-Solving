/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2021 21:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
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
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    long n,k;cin>>n>>k;
    long a,b,c,d;cin>>a>>b>>c>>d;
    b--,d--;
     if(b>d)swap(a,c),swap(b,d);
     long zero=max(0LL,min(b,d)-max(a,c)+1);
    long one=max(b,d)-min(a,c)+1-zero;
    long ex=max(0LL,c-b-1);
     //cout<<zero<<" "<<one<<" "<<ex<<endl;
     k-=1LL*zero*n;
    if(k<=0)
    {
      cout<<0<<endl;continue;
    }
    long ans=1LL*inf*inf,now=0;
    for(int i=1;i<=n;i++)
    {
      if(k>one)
      {
        now+=ex+one;k-=one;
        ans=min(ans,now+k*2);
      }
      else
      {
        ans=min(ans,now+ex+k);break;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}