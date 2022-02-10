/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-08 12:08:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 94                                         memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-poker-nim-1
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
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;int xx=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;xx^=x;
    }
    if(xx)cout<<"First\n";else cout<<"Second\n";
  }
  return 0;
}