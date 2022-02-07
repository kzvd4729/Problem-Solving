/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-14 19:32:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 290                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-1734
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1000000007;
int dp[11][2][2][(1<<11)+2],msk;
long cnt[(1<<11)+2],pr[(1<<11)+2];
vector<int>nm;
int dfs(int st,int ck,int f,int ksm)
{
  if(st>=nm.size())
  {
    if(f&&ksm==msk)return 1;
    return 0;
  }
  if(dp[st][ck][f][ksm]!=-1)return dp[st][ck][f][ksm];
  int now=0;
  if(!f)now+=dfs(st+1,0,0,ksm);
  else if(msk&(1<<0))
  {
    if(ck&&nm[st]==0)now+=dfs(st+1,1,f,ksm|(1<<0));
    else now+=dfs(st+1,0,f,ksm|(1<<0));
  }
  for(int i=1;i<=9;i++)
  {
    if(!(msk&(1<<i)))continue;
    if(!ck)now+=dfs(st+1,ck,1,ksm|(1<<i));
    else
    {
      if(i>nm[st])continue;
      if(i==nm[st])now+=dfs(st+1,1,1,ksm|(1<<i));
      else now+=dfs(st+1,0,1,ksm|(1<<i));
    }
  }
  return dp[st][ck][f][ksm]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;nm.clear();
    while(n)
    {
      nm.push_back(n%10);
      n/=10;
    }
    reverse(nm.begin(),nm.end());
    for(msk=1;msk<(1<<10);msk++)
    {
      memset(dp,-1,sizeof(dp));
      cnt[msk]=pr[msk]=dfs(0,1,0,0);
      //cout<<msk<<" "<<cnt[msk]<<endl;
    }
    long ans=0;
    for(int i=1;i<(1<<10);i++)
    {
      int dg=31-__builtin_clz(i);
      int a=(1<<dg);int b=i^a;
      for(int j=0;j<=b;j++)
      {
        if((j&b)==j)
        {
          int k=b^j;
          cnt[i]=(cnt[i]+(pr[a|j]*cnt[k]))%mod;
          //if(i==15)cout<<(a|j)<<" "<<k<<endl;
        }
      }
      ans=(ans+cnt[i])%mod;
    }
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}