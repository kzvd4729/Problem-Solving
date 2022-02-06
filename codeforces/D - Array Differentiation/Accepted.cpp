/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2021 13:00                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 30 ms                                           memory_used: 8100 KB                              
*  problem: https://codeforces.com/contest/1552/problem/D
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
 int n,a[N+2];
bool dfs(int i,int sm,int f)
{
  if(i>n)return ((sm==0) && f);
   bool ret=dfs(i+1,sm,f);
  ret|=dfs(i+1,sm+a[i],1);
  ret|=dfs(i+1,sm-a[i],1);
   return ret;
}
 int main()              
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     if(dfs(1,0,0))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
   }
    return 0;
}