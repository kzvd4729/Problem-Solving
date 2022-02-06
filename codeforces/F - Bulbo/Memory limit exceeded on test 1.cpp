/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/17/2019 17:02                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/575/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int n,in,aa[N+2],bb[N+2];
long dp[N+2][N+2][2];
long dfs(int id,int ls,int f)
{
  if(id>n)return 0;
  if(dp[id][ls][f]!=-1)return dp[id][ls][f];
  int pos;
  if(!ls)pos=in;
  else
  {
    if(f==0)pos=aa[ls];
    else pos=bb[ls];
  }
  long now;
  if(pos>=aa[id]&&pos<=bb[id])now=dfs(id+1,ls,f);
  else now=min(abs(pos-aa[id]),abs(pos-bb[id]))+dfs(id+1,ls,f);
  now=min(now,abs(pos-aa[id])+dfs(id+1,id,0));
  now=min(now,abs(pos-bb[id])+dfs(id+1,id,1));
  return dp[id][ls][f]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>in;
  for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i];
  memset(dp,-1,sizeof(dp));
   cout<<dfs(1,0,0)<<endl;
   return 0;
}