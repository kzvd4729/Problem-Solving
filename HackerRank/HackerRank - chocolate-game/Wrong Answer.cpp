/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-08 19:27:12                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-chocolate-game
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
const int N=1e6;
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],a[i]%=2;

  //for(int i=1;i<=n;i++)cout<<a[i];cout<<endl;

  int od=0,ev=0;if(a[1])od++;else ev++;
  long ans=0;
  for(int i=2;i<=n;i++)
  {
    if(a[i])
    {
      ans+=ev;
      swap(od,ev);od++;
    }
    else
    {
      ans+=od;ev++;
    }
    //cout<<od<<" "<<ev<<endl;
  }
  cout<<ans<<endl;
  return 0;
}