/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2020 14:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1028 ms                                         memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/229/problem/C
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
int d[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  long ans=1LL*n*(n-1)*(n-2)/6;
  ans-=1LL*(n-2)*m;
   for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    d[u]++,d[v]++;
  }
  for(int i=1;i<=n;i++)
    ans+=1LL*d[i]*(d[i]-1)/2;
  cout<<ans<<endl;
    return 0;
}