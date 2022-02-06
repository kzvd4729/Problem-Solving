/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/04/2020 21:00                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1375/problem/A
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
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;x=abs(x);
      if(i%2)x*=-1;
      cout<<x<<" ";
    }
    cout<<"\n";
  }
  return 0;
}