/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/09/2020 18:54                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 77 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/100694/problem/M
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,q;cin>>n>>q;
  while(q--)
  {
    int a,b;cin>>a>>b;
    int ans=(n/(a+b))*2,md=n%(a+b);
    ans+=(md>=a);
    cout<<ans<<'\n';
  }
  return 0;
}