/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/29/2020 20:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/1389/problem/A
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int l,r;cin>>l>>r;
    if(l+l>r)cout<<-1<<" "<<-1<<endl;
    else cout<<l<<" "<<l+l<<endl;
  }
    return 0;
}