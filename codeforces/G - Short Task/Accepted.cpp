/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/10/2021 20:46                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 1747 ms                                         memory_used: 78300 KB                             
*  problem: https://codeforces.com/contest/1512/problem/G
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
const int N=1e7,inf=1e9,mod=1e9+7;
 int sm[N+2];int ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)sm[j]+=i;
  }
    // long mx=0;
  // for(int i=1;i<=N;i++)mx=max(mx,sm[i]);
  // cout<<mx<<endl;
   memset(ans,-1,sizeof ans);
   for(int i=N;i>=1;i--)
  {
    if(sm[i]>N)continue;
    if(ans[sm[i]]=i);
  }
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    cout<<ans[n]<<'\n';
  }
    return 0;
}