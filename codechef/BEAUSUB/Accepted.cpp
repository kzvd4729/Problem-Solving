/****************************************************************************************
*  @author: kzvd4729                                         created: 28-07-2021 20:44:08                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.16 sec                                        memory_used: 18.7M                                
*  problem: https://www.codechef.com/COOK131A/problems/BEAUSUB
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
const int N=1e3,inf=1e9,mod=1e9+7;
int a[N+2],dp[N+2][N+2]; // [last e ki nisi][kotota distinct] 
int mx[N+2],tmp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(mx,0,sizeof mx);
    memset(dp,0,sizeof dp);
    memset(tmp,0,sizeof tmp);
    for(int i=1;i<=n;i++)
    {
      int x=a[i];
      for(int j=1;j<=k+1;j++)
      {
        dp[x][j]=max(dp[x][j]+1,mx[j-1]+1);
        tmp[j]=max(tmp[j],dp[x][j]);
      }
      for(int j=0;j<=k+1;j++)
      {
        mx[j]=tmp[j];
      }
    }
    cout<<mx[k+1]<<'\n';
  }
  return 0;
}