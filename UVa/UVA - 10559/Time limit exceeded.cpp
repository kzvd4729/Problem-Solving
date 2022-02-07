/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-14 22:06:02                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10559
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
int aa[N+2],bb[N+2],cc[N+2],n,dp[N+2][N+2][N+2][2];
int dfs(int lo,int hi,int sz,int f)
{
  if(lo==1&&hi==n)return sz*sz;
  int vl,now=0;if(!f)vl=bb[lo];else vl=bb[hi];
  if(lo>1)
  {
    now=max(now,sz*sz+dfs(lo-1,hi,cc[lo-1],0));
    if(f)now=max(now,cc[lo-1]*cc[lo-1]+dfs(lo-1,hi,sz,1));
    if(bb[lo-1]==vl)
    {
      if(f)now=max(now,dfs(lo-1,hi,sz+cc[lo-1],1));
      now=max(now,dfs(lo-1,hi,sz+cc[lo-1],0));
    }
  }
  if(hi<n)
  {
    now=max(now,sz*sz+dfs(lo,hi+1,cc[hi+1],1));
    if(!f)now=max(now,cc[hi+1]*cc[hi+1]+dfs(lo,hi+1,sz,0));
    if(bb[hi+1]==vl)
    {
      if(!f)now=max(now,dfs(lo,hi+1,sz+cc[hi+1],0));
      now=max(now,dfs(lo,hi+1,sz+cc[hi+1],1));
    }
  }
  return now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
    int cnt=1,ls=aa[1];int id=0;
    for(int i=2;i<=n;i++)
    {
      if(aa[i]==ls)cnt++;
      else
      {
        bb[++id]=ls;cc[id]=cnt;
        cnt=1;ls=aa[i];
      }
    }
    bb[++id]=ls;cc[id]=cnt;n=id;
    memset(dp,-1,sizeof(dp));int ans=0;
    for(int i=1;i<=n;i++)
      ans=max(ans,max(dfs(i,i,cc[i],0),dfs(i,i,cc[i],1)));
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}