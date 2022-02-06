/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/25/2021 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1506/problem/B
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
 string s;int n,k;
int dp[50+2][50+2];
int dfs(int i,int l)
{
  if(i-l>k)return inf;
  if(i==n)return 0;
   if(dp[i][l]!=-1)return dp[i][l];
   int ret=inf;
  if(s[i]=='.')ret=dfs(i+1,l);
  else
  {
    ret=min(ret,dfs(i+1,l));
    ret=min(ret,1+dfs(i+1,i));
  }
  return dp[i][l]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    cin>>n>>k;cin>>s;
     while(s.back()=='.')s.pop_back();
    reverse(s.begin(),s.end());
     while(s.back()=='.')s.pop_back();
    reverse(s.begin(),s.end());
      if((int)s.size()==1)
    {
      cout<<1<<endl;continue;
    }
    int ans=2;n=(int)s.size()-1;
     memset(dp,-1,sizeof dp);
    cout<<ans+dfs(1,0)<<endl;
       }
  return 0;
}