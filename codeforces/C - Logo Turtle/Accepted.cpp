/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/12/2020 11:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 8400 KB                              
*  problem: https://codeforces.com/contest/132/problem/C
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
string s;int n,dp[100+2][200+2][50+2][2];
int dfs(int i,int d,int m,int f)
{
  if(i==(int)s.size())
  {
    if(m%2==0)return abs(d);
    else return 0;
  }
  if(dp[i][d+100][m][f+1]!=-1)return dp[i][d+100][m][f+1];
  int ret=0;
  if(s[i]=='T')
  {
    ret=max(ret,dfs(i+1,d,m,f*-1));
    if(m)ret=max(ret,dfs(i+1,d+f,m-1,f));
  }
  else
  {
    ret=max(ret,dfs(i+1,d+f,m,f));
    if(m)ret=max(ret,dfs(i+1,d,m-1,f*-1));
  }
  return dp[i][d+100][m][f+1]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s>>n;memset(dp,-1,sizeof dp);
  cout<<dfs(0,0,n,1)<<endl;
  return 0;
}