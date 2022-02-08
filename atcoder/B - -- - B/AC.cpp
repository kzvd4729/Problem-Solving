/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-28 15:08:07                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 11 ms                                           memory_used: 3580 KB                              
*  problem: https://atcoder.jp/contests/arc112/tasks/arc112_b
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
const int N=1e6,inf=1e9,mod=1000000007;
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long b,c;cin>>b>>c;
   long psmx,psmn,ngmx,ngmn;
   if(b>=0)psmx=b+(c-2)/2;
  else psmx=-b+(c-1)/2;
   if(b>=0)psmn=b-c/2;
  else psmn=-b-(c-1)/2;
    if(b>=0)ngmn=-b-(c-1)/2;
  else ngmn=b-c/2;
   if(b>=0)ngmx=-b+(c-1)/2;
  else ngmx=b+(c-2)/2;
   long sub=0;
  long l=max(psmn,ngmn),r=min(psmx,ngmx);
  if(l<=r)sub=r-l+1;
   cout<<psmx-psmn+1+ngmx-ngmn+1-sub<<endl;
   //cout<<ngmn<<" "<<ngmx<<" "<<psmn<<" "<<psmx<<endl;
    return 0;
}