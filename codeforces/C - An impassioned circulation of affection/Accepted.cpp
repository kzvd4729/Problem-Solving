/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/19/2020 12:44                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 218 ms                                          memory_used: 5900 KB                              
*  problem: https://codeforces.com/contest/814/problem/C
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
const int N=1e6;
string s;int n;
int dp[1500+2][1000+2];
int cal(int m,char c)
{
  if(dp[m][c]!=-1)return dp[m][c];
  int mx=0,l=0,now=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]!=c)now++;
    while(now>m)now-=(s[l++]!=c);
    mx=max(mx,i-l+1);
  }
  return dp[m][c]=mx;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>s;int q;cin>>q;memset(dp,-1,sizeof dp);
  while(q--)
  {
    int x;char c;cin>>x>>c;
    cout<<cal(x,c)<<"\n";
  }
  return 0;
}