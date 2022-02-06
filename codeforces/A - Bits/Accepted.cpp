/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/10/2020 11:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/484/problem/A
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
const int N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>q;
  while(q--)
  {
    long l,r;cin>>l>>r;long mx=__builtin_popcountll(r),mn=r;
    for(int i=60;i>=0;i--)
    {
      if(!(r&(1LL<<i)))continue;long tmp=r;//cout<<tmp<<" ";
      tmp^=(1LL<<i);//cout<<tmp<<endl;
      for(int j=i-1;j>=0;j--)
        if(!(tmp&(1LL<<j)))tmp^=(1LL<<j);
      if(tmp<l)continue;
      if(__builtin_popcountll(tmp)>=mx)mx=__builtin_popcountll(tmp),mn=min(mn,tmp);
    }
    cout<<mn<<endl;
  }
    return 0;
}