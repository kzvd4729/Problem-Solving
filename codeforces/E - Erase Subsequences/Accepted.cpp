/****************************************************************************************
*  @author: kzvd4729                                         created: May/29/2021 18:57                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 374 ms                                          memory_used: 254300 KB                            
*  problem: https://codeforces.com/contest/1303/problem/E
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
const int N=400,inf=1e9,mod=1000000007;
 string a,b;
 int dp[N+2][N+2][N+2],f;
 void dfs(int st,int nw,int i,int j)
{
  if(nw>=(int)b.size() && j>=st)f=1;
  if(f)return ;
   if(i>=(int)a.size())return ;
   if(dp[st][nw][i]>=j)return ;
  dp[st][nw][i]=j;
   if((j<st) && (a[i]==b[j]))dfs(st,nw,i+1,j+1);
  if((nw<(int)b.size()) && (a[i]==b[nw]))dfs(st,nw+1,i+1,j);
  dfs(st,nw,i+1,j);
 }
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    cin>>a>>b;f=0;
     for(int i=0;i<=(int)a.size();i++)
    {
      for(int j=0;j<=(int)a.size();j++)
      {
        for(int k=0;k<=(int)a.size();k++)dp[i][j][k]=-1;
      }
    }
    for(int i=0;i<(int)b.size();i++)
      dfs(i,i,0,0);
     if(f)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}