/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/04/2021 20:44                        
*  solution_verdict: Time limit exceeded on test 2           language: GNU C++17 (64)                          
*  run_time: 2000 ms                                         memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1535/problem/B
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
  int a[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     sort(a+1,a+n+1,[&](int x,int y){
      return (x%2)==0;
    });
     int cnt=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)cnt+=(__gcd(a[i],2*a[j])>1);
    }
    cout<<cnt<<'\n';
  }
       return 0;
}