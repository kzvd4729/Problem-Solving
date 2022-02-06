/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/04/2020 21:02                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 32500 KB                             
*  problem: https://codeforces.com/contest/1409/problem/F
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
const int N=200;
string s,t;
int dp[N+2][N+2][N+2];
int dfs(int id,int mv,int a)
{
  if(id==s.size())return 0;
  if(dp[id][mv][a]!=-1)return dp[id][mv][a];
  int ret;
  if(s[id]==t[0])
  {
    ret=dfs(id+1,mv,a+1);//same
    if(mv)ret=max(ret,a+dfs(id+1,mv-1,a));//b
  }
  else if(s[id]==t[1])
  {
    ret=a+dfs(id+1,mv,a);//b
    if(mv)ret=max(ret,dfs(id+1,mv-1,a+1));//a
  }
  else
  {
    ret=dfs(id+1,mv,a);//other
    if(mv)ret=max(ret,dfs(id+1,mv-1,a+1));
    if(mv)ret=max(ret,a+dfs(id+1,mv-1,a));
  }
  return dp[id][mv][a]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  cin>>s>>t;
   if(t[0]==t[1])
  {
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]==t[0])cnt++;
      else if(k)k--,cnt++;
    }
    cout<<(cnt*(cnt-1))/2<<'\n';exit(0);
  }
  memset(dp,-1,sizeof dp);
  cout<<dfs(0,k,0)<<endl;
   return 0;
}