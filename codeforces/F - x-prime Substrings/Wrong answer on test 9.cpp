/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2020 19:18                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 41900 KB                             
*  problem: https://codeforces.com/contest/1400/problem/F
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
#define long long long
using namespace std;
const int N=1e3;
string s;int x,n,dp[N+2][20+2][20+2][20+2];
int dfs(int i,int a,int b,int c)
{
  if(i==n)return 0;
  if(a>b)swap(a,b);if(a>c)swap(a,c);if(b>c)swap(b,c);
  int aa=min(21,a-i),bb=min(21,b-i),cc=min(21,c-i);
  if(i==a)return dp[i][aa][bb][cc]=dfs(i+1,b,c,n);
   if(s[i]-'0'==x)return dp[i][aa][bb][cc]=1+dfs(i+1,a,b,c);
   if(dp[i][aa][bb][cc]!=-1)return dp[i][aa][bb][cc];
   vector<int>v;int sm=0,ls;
  for(int j=i;j<n;j++)
  {
    if(j==a||j==b||j==c)continue;
    int nm=s[j]-'0';if(sm+nm>x)break;
    v.push_back(nm);sm+=nm,ls=j;
     if(x%nm==0)return dp[i][aa][bb][cc]=dfs(i+1,a,b,c);
  }
  if(sm!=x)return dp[i][aa][bb][cc]=dfs(i+1,a,b,c);
  for(int j=0;j<v.size();j++)
  {
    int sm=0;
    for(int k=j;k<v.size();k++)
    {
      sm+=v[k];
      if((sm!=x)&&(x%sm==0))return dp[i][aa][bb][cc]=dfs(i+1,a,b,c);
    }
  }
  int nx=21;for(int j=ls+1;j<n;j++)if(j!=a&&j!=b&&j!=c){nx=s[j]-'0';break;}
  int mn=1e9;
  for(int j=i+1;j<=ls;j++)
  {
    if(j==a||j==b||j==c)continue;
    if(x%(sm-(s[j]-'0')+nx)==0)continue;
    if(a==n)mn=min(mn,1+dfs(i+1,j,b,c));
    else if(b==n)mn=min(mn,1+dfs(i+1,a,j,c));
    else if(c==n)mn=min(mn,1+dfs(i+1,a,b,j));
  }
  return dp[i][aa][bb][cc]=mn;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s>>x;n=s.size();
  memset(dp,-1,sizeof dp);
  cout<<dfs(0,n,n,n)<<endl;
  return 0;
}