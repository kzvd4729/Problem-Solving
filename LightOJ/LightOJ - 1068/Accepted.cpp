/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-04 23:57:05                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 432                                        memory_used (MB): 2.9                             
*  problem: https://vjudge.net/problem/LightOJ-1068
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int k,t,dp[10][3][104][104],a,b,tc;
vector<int>v1,v2;
int dfs1(int st,int ck,int sum,int md)
{
  if(st==v2.size())
  {
    if(sum==0&&md==0)return 1;
    else return 0;
  }
  if(dp[st][ck][sum][md]!=-1)return dp[st][ck][sum][md];
  int cnt=0;
  if(ck==0)
  {
    for(int i=0;i<=9;i++)
    {
      cnt+=dfs1(st+1,0,(sum+i)%k,(md*10+i)%k);
    }
  }
  else
  {
    for(int i=0;i<v2[st];i++)
    {
      cnt+=dfs1(st+1,0,(sum+i)%k,(md*10+i)%k);
    }
    cnt+=dfs1(st+1,1,(sum+(int)(v2[st]))%k,(md*10+(int)(v2[st]))%k);
  }
  return dp[st][ck][sum][md]=cnt;
}
int dfs2(int st,int ck,int sum,int md)
{
  if(st==v1.size())
  {
    if(sum==0&&md==0)return 1;
    else return 0;
  }
  if(dp[st][ck][sum][md]!=-1)return dp[st][ck][sum][md];
  int cnt=0;
  if(ck==0)
  {
    for(int i=0;i<=9;i++)
    {
      cnt+=dfs2(st+1,0,(sum+i)%k,(md*10+i)%k);
    }
  }
  else
  {
    for(int i=0;i<v1[st];i++)
    {
      cnt+=dfs2(st+1,0,(sum+i)%k,(md*10+i)%k);
    }
    cnt+=dfs2(st+1,1,(sum+(int)(v1[st]))%k,(md*10+(int)(v1[st]))%k);
  }
  return dp[st][ck][sum][md]=cnt;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>a>>b>>k;

    cout<<"Case "<<++tc<<": ";
    if(k>100)
    {
      cout<<0<<endl;
      continue;
    }
    memset(dp,-1,sizeof(dp));
    v1.clear();
    v2.clear();
    while(b)
    {
      v2.push_back(b%10);
      b/=10;
    }
    reverse(v2.begin(),v2.end());
    a--;
    while(a)
    {
      v1.push_back(a%10);
      a/=10;
    }
    reverse(v1.begin(),v1.end());

    int x1=dfs1(0,1,0,0);
    memset(dp,-1,sizeof(dp));
    cout<<x1-dfs2(0,1,0,0)<<endl;
  }
  return 0;
}