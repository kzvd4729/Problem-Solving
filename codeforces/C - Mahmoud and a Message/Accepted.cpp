/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2018 16:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/766/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long mod=1e9+7;
int aa[N+2],a,b=mod;long dp[N+2][N+2],dp2[N+2][N+2];
long dp3[N+2][N+2];
string s;
long dfs(int st,int last,int mn)
{
  if(st==s.size())
  {
    if(mn==mod)return 1;
    else return 0;
  }
  mn=min(mn,aa[s[st]-'a']);
  if(st-last>mn)return 0;
   if(dp[st][last+1]!=-1)return dp[st][last+1];
   long here=0;
  here=(here+dfs(st+1,last,mn))%mod;
  here=(here+dfs(st+1,st,mod))%mod;
   return dp[st][last+1]=here;
}
long dfs2(int st,int last,int mn)
{
  if(st==s.size())
  {
    if(mn==mod)return 0;
    else return -mod;
  }
  mn=min(mn,aa[s[st]-'a']);
  if(st-last>mn)return -mod;
   if(dp2[st][last+1]!=-1)return dp2[st][last+1];
   long here=-mod;
  here=max(here,max(st-last*1LL,dfs2(st+1,st,mod)));
  here=max(here,dfs2(st+1,last,mn));
   return dp2[st][last+1]=here;
}
long dfs3(int st,int last,int mn)
{
  if(st==s.size())
  {
    if(mn==mod)return 0;
    else return mod;
  }
  mn=min(mn,aa[s[st]-'a']);
  if(st-last>mn)return mod;
   if(dp3[st][last+1]!=-1)return dp3[st][last+1];
   long here=mod;
  here=min(here,1+dfs3(st+1,st,mod));
  here=min(here,dfs3(st+1,last,mn));
   return dp3[st][last+1]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>s;
  for(int i=0;i<26;i++)
    cin>>aa[i];
   memset(dp,-1,sizeof(dp));
  memset(dp2,-1,sizeof(dp2));
  memset(dp3,-1,sizeof(dp3));
   cout<<dfs(0,-1,mod)<<endl;
  cout<<dfs2(0,-1,mod)<<endl;
  cout<<dfs3(0,-1,mod)<<endl;
   return 0;
}