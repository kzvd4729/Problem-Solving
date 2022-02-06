/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/18/2020 13:33                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 202 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/526/problem/C
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
const int N=2e5,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long c,ha,hb,wa,wb;cin>>c>>ha>>hb>>wa>>wb;
   long ans=0;
  for(int i=0;i<=1e7;i++)
  {
    if(wa*i>c)continue;
    long now=ha*i;long rm=c-i*wa;
    now+=hb*(rm/wb);
     ans=max(ans,now);
  }
  swap(ha,hb);swap(wa,wb);
  for(int i=0;i<=1e7;i++)
  {
    if(wa*i>c)continue;
    long now=ha*i;long rm=c-i*wa;
    now+=hb*(rm/wb);
     ans=max(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}