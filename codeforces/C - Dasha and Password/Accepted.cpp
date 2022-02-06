/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/01/2018 20:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/761/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e6;
const int N=50;
int n,m,dp[N+2][2][2][2];
string s[N+2];
int dfs(int st,int nm,int sm,int ch)
{
  if(st>n)
  {
    if(nm&&sm&&ch)return 0;
    else return inf;
  }
  if(dp[st][nm][sm][ch]!=-1)return dp[st][nm][sm][ch];
  int nmm=inf,smm=inf,chh=inf,here=inf;
  for(int i=0;i<s[st].size();i++)
  {
    if(s[st][i]>='0'&&s[st][i]<='9')
      nmm=min(nmm,min(i,(int)s[st].size()-i));
    else if(s[st][i]>='a'&&s[st][i]<='z')
      smm=min(smm,min(i,(int)s[st].size()-i));
    else
      chh=min(chh,min(i,(int)s[st].size()-i));
  }
  here=min(here,nmm+dfs(st+1,1,sm,ch));
  here=min(here,smm+dfs(st+1,nm,1,ch));
  here=min(here,chh+dfs(st+1,nm,sm,1));
  return dp[st][nm][sm][ch]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>s[i];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0,0,0)<<endl;
  return 0;
}