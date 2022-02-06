/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/25/2020 21:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 13300 KB                             
*  problem: https://codeforces.com/contest/1373/problem/D
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
long mx(vector<long>v)
{
  long ret=0,now=0;
  for(long i=0;i<v.size();i++)
  {
    now+=v[i];if(now<0)now=0;
    ret=max(ret,now);
  }
  return ret;
}
long a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;long ans=0;
    for(long i=0;i<n;i++)
    {
      cin>>a[i];if(i%2==0)ans+=a[i];
    }
    vector<long>v;
    for(long i=1;i<n;i+=2)
      v.push_back(a[i]-a[i-1]);
    long m=mx(v);v.clear();
     for(long i=1;i<n-1;i+=2)
      v.push_back(a[i]-a[i+1]);
    m=max(m,mx(v));
    cout<<ans+m<<"\n";
   }
  return 0;
}