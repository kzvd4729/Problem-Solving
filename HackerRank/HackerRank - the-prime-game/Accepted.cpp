/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-08 18:28:58                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 682                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-the-prime-game
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
int grundy(long x)
{
  return (x%9)/2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;int xx=0;
    for(int i=1;i<=n;i++)
    {
      long x;cin>>x;xx^=grundy(x);
    }
    if(xx==0)cout<<"Sandy\n";
    else cout<<"Manasa\n";
  }
  return 0;
}