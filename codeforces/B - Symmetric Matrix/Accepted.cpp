/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/28/2020 14:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1426/problem/B
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
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    int f=0;
    for(int i=1;i<=n;i++)
    {
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      if(b==c)f=1;
    }
    if(f&&m%2==0)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}