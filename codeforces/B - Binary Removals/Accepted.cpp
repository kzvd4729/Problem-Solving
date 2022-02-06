/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2021 21:08                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1499/problem/B
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
 int dp[N+2][2][2];
string s;
bool dfs(int i,int f,int ls)
{
  if(i==(int)s.size())return 1;
   if(dp[i][f][ls]!=-1)return dp[i][f][ls];
   int now=s[i]-'0';
  int ret=0;
  if(now>=ls)ret|=dfs(i+1,0,now);
  if(f==0)ret|=dfs(i+1,1,ls);
   return dp[i][f][ls]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    cin>>s;
    for(int i=0;i<=(int)s.size();i++)
    {
      for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)dp[i][j][k]=-1;
    }
    if(dfs(0,0,0))cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}