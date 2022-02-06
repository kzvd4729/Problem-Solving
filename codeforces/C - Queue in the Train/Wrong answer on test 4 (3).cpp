/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/06/2020 19:27                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++17                               
*  run_time: 108 ms                                          memory_used: 38300 KB                             
*  problem: https://codeforces.com/contest/1239/problem/C
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
long a[N+2];pair<long,long>b[N+2];
long ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,p;cin>>n>>p;
  for(long i=1;i<=n;i++)cin>>a[i],b[i].first=a[i],b[i].second=i;
  sort(b+1,b+n+1);
    long tm=0;long pt=1;set<long>st;
  while(true)
  {
    if(pt>n&&st.size()==0)break;
    if(st.size()==0)tm=max(tm,b[pt].first*1LL);
    while(pt<=n)
    {
      if(b[pt].first<=tm)st.insert(b[pt++].second);
      else break;
    }
    long bg=*st.begin();st.erase(bg);
    tm+=p;ans[bg]=tm;
  }
  for(long i=1;i<=n;i++)assert(ans[i]);
  for(long i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}