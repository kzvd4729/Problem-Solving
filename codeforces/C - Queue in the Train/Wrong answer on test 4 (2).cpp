/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/06/2020 19:27                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++17                               
*  run_time: 124 ms                                          memory_used: 26500 KB                             
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
const int N=1e6;
int a[N+2];pair<int,int>b[N+2];
long ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,p;cin>>n>>p;
  for(int i=1;i<=n;i++)cin>>a[i],b[i].first=a[i],b[i].second=i;
  sort(b+1,b+n+1);
    long tm=0;int pt=1;set<int>st;
  while(true)
  {
    if(pt>n&&st.size()==0)break;
    if(st.size()==0)tm=max(tm,b[pt].first*1LL);
    while(pt<=n)
    {
      if(b[pt].first<=tm)st.insert(b[pt++].second);
      else break;
    }
    int bg=*st.begin();st.erase(bg);
    tm+=p;ans[bg]=tm;
  }
  for(int i=1;i<=n;i++)assert(ans[i]);
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}