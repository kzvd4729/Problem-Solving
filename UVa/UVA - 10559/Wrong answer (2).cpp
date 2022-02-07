/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-13 17:13:20                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10559
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
int n,aa[N+2],dp[N+2][N+2][N+2][2];
int dfs(int lt,int rt,int sz,int f)
{
  if(lt==1&&rt==n)return sz*sz;
  if(dp[lt][rt][sz][f]!=-1)return dp[lt][rt][sz][f];
  int now=0,vl;if(!f)vl=aa[lt];else vl=aa[rt];
  if(lt>1)
  {
    if(aa[lt-1]==vl)now=max(now,dfs(lt-1,rt,sz+1,f));
    now=max(now,sz*sz+dfs(lt-1,rt,1,0));
  }
  if(rt<n)
  {
    if(aa[rt+1]==vl)now=max(now,dfs(lt,rt+1,sz+1,f));
    now=max(now,sz*sz+dfs(lt,rt+1,1,1));
  }
  return dp[lt][rt][sz][f]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
    memset(dp,-1,sizeof(dp));int ans=0;
    for(int i=1;i<=n;i++)
      ans=max(ans,dfs(i,i,1,0));
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}