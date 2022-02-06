/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/22/2020 14:53                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 826 ms                                          memory_used: 121500 KB                            
*  problem: https://codeforces.com/contest/425/problem/C
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
const int N=1e5;
int a[N+2],dp[N+2][300+2];
vector<int>po[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,s,e;cin>>n>>m>>s>>e;
   for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    po[x].push_back(i);
  }
  for(int i=0;i<N+2;i++)
  {
    for(int j=1;j<300+2;j++)dp[i][j]=m+1;
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=300;j++)
    {
      dp[i][j]=dp[i-1][j];int x=a[i];
      int id=upper_bound(po[x].begin(),po[x].end(),dp[i-1][j-1])-po[x].begin();
      if(id<po[x].size())dp[i][j]=min(dp[i][j],po[x][id]);
        if(dp[i][j]<=m&&j*e+i+dp[i][j]<=s)ans=max(ans,j);
    }
  }
  cout<<ans<<endl;
  return 0;
}