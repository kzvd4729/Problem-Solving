/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/31/2018 11:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 21000 KB                             
*  problem: https://codeforces.com/contest/1096/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,aa[N+2];long dp[N+2][2][2][2][2];
string s;
long dfs(int st,int a,int b,int c,int d)
{
  if(st==s.size())return 0;
  if(dp[st][a][b][c][d]!=-1)return dp[st][a][b][c][d];
  long now=1e17;
  if(s[st]=='h')
  {
    now=min(now,aa[st]+dfs(st+1,a,b,c,d));
    now=min(now,dfs(st+1,1,b,c,d));
  }
  else if(s[st]=='a')
  {
    now=min(now,aa[st]+dfs(st+1,a,b,c,d));
    if(a)now=min(now,dfs(st+1,1,1,c,d));
    else now=min(now,dfs(st+1,a,b,c,d));
  }
  else if(s[st]=='r')
  {
    now=min(now,aa[st]+dfs(st+1,a,b,c,d));
    if(b)now=min(now,dfs(st+1,1,1,1,d));
    else now=min(now,dfs(st+1,a,b,c,d)); 
  }
  else if(s[st]=='d')
  {
    now=min(now,aa[st]+dfs(st+1,a,b,c,d));
    if(c);//now=min(now,dfs(st+1,1,1,1,d));
    else now=min(now,dfs(st+1,a,b,c,d)); 
  }
  else now=min(now,dfs(st+1,a,b,c,d));
  return dp[st][a][b][c][d]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;cin>>s;
  for(int i=0;i<n;i++)
    cin>>aa[i];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0,0,0,0)<<endl;
   return 0;
}