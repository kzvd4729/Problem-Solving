/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2020 12:22                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 327 ms                                          memory_used: 196100 KB                            
*  problem: https://codeforces.com/contest/983/problem/B
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
const int N=5e3;
int a[N+2][N+2],dp[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i][i],dp[i][i]=a[i][i];
   for(int l=2;l<=n;l++)
  {
    for(int i=1;i<=n;i++)
    {
      int j=i+l-1;if(j>n)break;
      a[i][j]=(a[i][j-1]^a[i+1][j]);
       dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
      dp[i][j]=max(dp[i][j],a[i][j]);
    }
  }
  int q;cin>>q;
  while(q--)
  {
    int l,r;cin>>l>>r;
    cout<<dp[l][r]<<'\n';
  }
   return 0;
}