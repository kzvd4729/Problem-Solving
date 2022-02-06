/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/07/2018 21:52                        
*  solution_verdict: Time limit exceeded on test 2           language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1036/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e5;
long dp[22][3][3][22];
vector<long>v;
long dfs(long st,long ck,long f,long nm)
{
  if(nm>3)return 0;
  if(st==v.size())
  {
    if(f)return 1;
    else return 0;
  }
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
  return here;
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
  //cout<<10000*22*22*3*3<<endl;
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long l,r;cin>>l>>r;
    v=arr(r);
    memset(dp,-1,sizeof(dp));
    long rr=dfs(0,1,0,0);
    v=arr(l-1);
    memset(dp,-1,sizeof(dp));
    cout<<rr-dfs(0,1,0,0)<<endl;
  }
  return 0;
}