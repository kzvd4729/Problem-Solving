/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/08/2018 12:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1036/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e5;
long dp[22][3][3][4];
vector<long>v;
long dfs(long st,long ck,long f,long nm)
{
  if(nm>3)return 0;
  if(st==v.size())
  {
    if(f)return 1;
    else return 0;
  }
  if(dp[st][ck][f][nm]!=-1)return dp[st][ck][f][nm];
  long here=0;
  if(ck==0)
  {
    for(long i=0;i<=9;i++)
    {
      if(i==0)here+=dfs(st+1,0,f,nm);
      else here+=dfs(st+1,0,1,nm+1);
    }
  }
  else
  {
    for(long i=0;i<=v[st];i++)
    {
      if(i==v[st])
      {
        if(i==0)here+=dfs(st+1,1,f,nm);
        else here+=dfs(st+1,1,1,nm+1);
      }
      else if(i==0)here+=dfs(st+1,0,f,nm);
      else here+=dfs(st+1,0,1,nm+1);
    }
  }
  return dp[st][ck][f][nm]=here;
}
vector<long>arr(long x)
{
  vector<long>ret;
  while(x)
  {
    ret.push_back(x%10);
    x/=10;
  }
  reverse(ret.begin(),ret.end());
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long l,r;cin>>l>>r;
    //l=1;r=1e18;
    v=arr(r);
    memset(dp,-1,sizeof(dp));
    long rr=dfs(0,1,0,0);
    v=arr(l-1);
    memset(dp,-1,sizeof(dp));
    cout<<rr-dfs(0,1,0,0)<<endl;
  }
  return 0;
}