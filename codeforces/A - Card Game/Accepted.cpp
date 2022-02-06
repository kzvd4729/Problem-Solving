/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2020 14:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1270/problem/A
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
    int n,a,b;cin>>n>>a>>b;int f=0;
    for(int i=1;i<=a;i++)
    {
      int x;cin>>x;if(x==n)f=1;
    }
    for(int i=1;i<=b;i++)
    {
      int x;cin>>x;
    }
    if(f)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}