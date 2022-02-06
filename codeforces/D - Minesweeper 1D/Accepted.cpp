/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2020 14:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 126700 KB                            
*  problem: https://codeforces.com/contest/404/problem/D
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
const int N=1e6,mod=1e9+7;
int n,dp[N+2][4][4];string s;
bool ck(int a,int b,int c)
{
  int bm=(a==3)+(c==3);bool vr;
  if(b<3)vr=bm==b;else vr=true;
  return vr;
}
int dfs(int i,int a,int b)
{
  if(i==n)return ck(a,b,0);
  if(dp[i][a][b]!=-1)return dp[i][a][b];
  if(s[i]=='*')return dp[i][a][b]=ck(a,b,3)*dfs(i+1,b,3);
  else if(s[i]!='?')return dp[i][a][b]=ck(a,b,s[i]-'0')*dfs(i+1,b,s[i]-'0');
  else
  {
    int ret=0;
    ret=(ret+ck(a,b,0)*dfs(i+1,b,0))%mod;
    ret=(ret+ck(a,b,1)*dfs(i+1,b,1))%mod;
    ret=(ret+ck(a,b,2)*dfs(i+1,b,2))%mod;
    ret=(ret+ck(a,b,3)*dfs(i+1,b,3))%mod;
    return dp[i][a][b]=ret;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s;n=s.size();
  memset(dp,-1,sizeof dp);
  cout<<(dfs(0,0,0)+dfs(0,0,1))%mod<<endl;
   return 0;
}