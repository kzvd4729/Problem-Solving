/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-24 15:24:49                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 10                                         memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-PR003004
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,dp[20][3][200],ans;
string a,b,tmp;
long dfs(long st,long ck,long sum)
{
  if(st==tmp.size())return sum;
  if(dp[st][ck][sum]!=-1)return dp[st][ck][sum];
  long cnt=0;
  if(ck==0)
  {
    for(long i=0;i<=9;i++)
      cnt+=dfs(st+1,0,sum+i);
  }
  else
  {
    for(long i=0;i<=tmp[st]-'0';i++)
    {
      if(i<tmp[st]-'0')cnt+=dfs(st+1,0,sum+i);
      else cnt+=dfs(st+1,1,sum+i);
    }
  }
  return dp[st][ck][sum]=cnt;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>a>>b;
    tmp=b;
    memset(dp,-1,sizeof(dp));
    long p1=dfs(0,1,0);
    tmp=a;
    memset(dp,-1,sizeof(dp));
    long p2=dfs(0,1,0);
    ans=p1-p2;
    for(long i=0;i<a.size();i++)
      ans+=a[i]-'0';
    cout<<ans<<endl;
  }
  return 0;
}