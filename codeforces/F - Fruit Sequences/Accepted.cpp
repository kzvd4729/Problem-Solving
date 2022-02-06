/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/03/2020 15:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 3000 KB                              
*  problem: https://codeforces.com/contest/1428/problem/F
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
const int N=5e5;
int bit[N+2];
void upd(int x,int vl)
{
  for( ;x<=N;x+=x&-x)bit[x]+=vl;
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  long sm=0,ans=0;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(s[i-1]=='0')
    {
      ans+=sm;cnt=0;continue;
    }
    cnt++;int lo=1,hi=i,md;
    while(lo<hi)
    {
      md=(lo+hi)/2;
      if(get(md)>=cnt)lo=md+1;
      else hi=md;
    }
    sm+=(i-lo+1);upd(lo,1);upd(i+1,-1);
    ans+=sm;//cout<<sm<<endl;
  }
  cout<<ans<<endl;
  return 0;
}