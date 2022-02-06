/****************************************************************************************
*  @author: kzvd4729#                                        created: Sep/25/2020 13:32                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1420/problem/A
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
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int f=0;
    for(int i=1;i<n;i++)if(a[i]<=a[i+1])f=1;
     if(f)cout<<"YES\n";else cout<<"NO\n";
  }
  return 0;
}