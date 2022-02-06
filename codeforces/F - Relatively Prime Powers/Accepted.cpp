/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/22/2020 22:08                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 296 ms                                          memory_used: 12400 KB                             
*  problem: https://codeforces.com/contest/1036/problem/F
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
const long L=1e18;
bool isSqure(long x)
{
  long sq=sqrt(x+1);
  return sq*sq==x;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<long>v;
  for(int i=2;i<=N;i++)
  {
    long p=1LL*i*i;
    while(L/p>=i)
    {
      p*=i;
      if(!isSqure(p))v.push_back(p);
    }
  }
  sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    long mn=upper_bound(v.begin(),v.end(),n)-v.begin();
    mn+=sqrt(n);
    cout<<n-mn<<"\n";
  }
  return 0;
}