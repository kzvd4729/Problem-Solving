/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2021 19:22                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1508/problem/B
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
const long Inf=1LL*inf*inf;
 long dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;long k;cin>>n>>k;
     dp[n+1]=1;long sm=1;
    for(int i=n;i>=1;i--)
    {
      dp[i]=sm;
      sm+=dp[i];
       if(sm>Inf)sm=Inf+1;
    }
     if(dp[1]<k)
    {
      cout<<-1<<endl;
      continue;
    }
     for(int i=1;i<=n;i++)
    {
      for(int j=i+1; ;j++)
      {
        if(dp[j]>=k)
        {
          for(int ii=j-1;ii>=i;ii--)cout<<ii<<" ";
          i=j-1;break;
        }
        else k-=dp[j];
      }
    }
    cout<<endl;
  }
  return 0;
}