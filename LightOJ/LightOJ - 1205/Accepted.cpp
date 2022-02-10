/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-20 00:46:16                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1                                          memory_used (MB): 2.2                             
*  problem: https://vjudge.net/problem/LightOJ-1205
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
long dp[20][3][3];
vector<int>aa;
vector<int>convert(long x)
{
  vector<int>ret;
  while(x)
  {
    ret.push_back(x%10);
    x/=10;
  }
  reverse(ret.begin(),ret.end());
  if(ret.size()==0)ret.push_back(0);
  return ret;
}
long dfs(int st,int ck1,int ck2)
{
  int ts=aa.size()-1-st;
  if(ts<st)
  {
    if(ck1&&ck2==2)return 0;
    else return 1;
  }
  if(dp[st][ck1][ck2]!=-1)return dp[st][ck1][ck2];
  long here=0;
  int i=0;if(st==0)i=1;
  for( ;i<=9;i++)
  {
    if(ck1&&i>aa[st])continue;
    if(ck1&&i==aa[st])
    {
      int tmp;
      if(i<aa[ts])tmp=0;
      else if(i>aa[ts])tmp=2;
      else tmp=ck2;
      here+=dfs(st+1,ck1,tmp);
    }
    else here+=dfs(st+1,0,0);
  }
  return dp[st][ck1][ck2]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    long a,b;cin>>a>>b;
    if(a<b)swap(a,b);
    aa=convert(a);
    long ans1=0,ml=9;

    for(int i=1; ;i++)
    {
      if(i==aa.size())break;
      ans1+=ml;
      if(i>1&&(i%2==0))ml*=10;
    }
    memset(dp,-1,sizeof(dp));
    ans1+=dfs(0,1,1);
    if(!b)
    {
      cout<<"Case "<<++tc<<": "<<ans1+1<<"\n";
      continue;
    }
    aa=convert(b-1);
    long ans2=0;ml=9;
    for(int i=1; ;i++)
    {
      if(i==aa.size())break;
      ans2+=ml;
      if(i>1&&(i%2==0))ml*=10;
    }
    memset(dp,-1,sizeof(dp));
    ans2+=dfs(0,1,1);
    cout<<"Case "<<++tc<<": "<<ans1-ans2<<"\n";
  }
  return 0;
}