/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2021 15:05                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++17 (64)                          
*  run_time: 3000 ms                                         memory_used: 35200 KB                             
*  problem: https://codeforces.com/contest/1511/problem/E
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
const int N=1e6,inf=1e9,mod=998244353;
  string s[N+2];int pw[N+2],tt;
 int cal(int x)
{
  int ret=0;
  for(int i=1;i<=x;i++)
  {
    for(int j=i-2;j>=0;j-=2)
    {
      ret=(ret+pw[tt-(i-j+1-(j==0))])%mod;
    }
    //cout<<i<<" "<<ret<<endl;
  }
  return ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>s[i],s[i]="*"+s[i];
   pw[0]=1;
  for(int i=1;i<=n*m;i++)pw[i]=(pw[i-1]*2)%mod;
    int cnt=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      if(s[i][j]=='o')cnt++;
  }
   int ans=0;tt=cnt;
  for(int i=1;i<=n;i++)
  {
    int cnt=0;
    for(int j=1;j<=m;j++)
    {
      if(s[i][j]=='o')cnt++;
      else
      {
        ans=(ans+cal(cnt))%mod;
        cnt=0;
      }
    }
    ans=(ans+cal(cnt))%mod;
  }
  //cout<<ans<<endl;
   for(int j=1;j<=m;j++)
  {
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
      if(s[i][j]=='o')cnt++;
      else
      {
        ans=(ans+cal(cnt))%mod;
        cnt=0;
      }
    }
    ans=(ans+cal(cnt))%mod;
  }
   cout<<ans<<endl;
   return 0;
}