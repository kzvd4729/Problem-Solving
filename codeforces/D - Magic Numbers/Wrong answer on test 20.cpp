/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2018 17:34                        
*  solution_verdict: Wrong answer on test 20                 language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 128900 KB                            
*  problem: https://codeforces.com/contest/628/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
int m,d;
int dp[2002][2][2][2002][2];
string a,b;
int dfs(int st,int ck,int rl,int md,int last)
{
  if(st==b.size())
  {
    if(md==0)return 1;
    else return 0;
  }
  last=last%2;
  //last=int(last<b[st]-'0');
  if(dp[st][ck][rl%2][md][last]!=-1)return dp[st][ck][rl%2][md][last];
  long cnt=0;
  if(rl&1)
  {
    if(ck==0||d<int(b[st]-'0'))cnt+=(dfs(st+1,0,rl+1,(md*10+d)%m,d)*1LL);
    else if(d==int(b[st]-'0'))cnt+=(dfs(st+1,1,rl+1,(md*10+d)%m,d)*1LL);
  }
  else
  {
    for(int i=0;i<=9;i++)
    {
      if(i==d)continue;
      if(ck==0)
      {
        if(rl==0&&i==0)cnt+=(dfs(st+1,0,rl,(md*10+i)%m,i)*1LL);
        else cnt+=(dfs(st+1,0,rl+1,(md*10+i)%m,i)*1LL);
      }
      else
      {
        if(i<int(b[st]-'0'))
        {
          if(rl==0&&i==0)cnt+=(dfs(st+1,0,rl,(md*10+i)%m,i)*1LL);
          else cnt+=(dfs(st+1,0,rl+1,(md*10+i)%m,i)*1LL);
        }
        else if(i==int(b[st]-'0'))
        {
          if(rl==0&&i==0)cnt+=(dfs(st+1,1,rl,(md*10+i)%m,i)*1LL);
          else cnt+=(dfs(st+1,1,rl+1,(md*10+i)%m,i)*1LL);
        }
      }
    }
  }
  return dp[st][ck][rl%2][md][last]=cnt%mod;
}
int dfs2(int st,int ck,int rl,int md,int last)
{
  if(st==a.size())
  {
    if(md==0)return 1;
    else return 0;
  }
  last=last%2;
  //last=int(last<a[st]-'0');
  if(dp[st][ck][rl%2][md][last]!=-1)return dp[st][ck][rl%2][md][last];
  long cnt=0;
  if(rl&1)
  {
    if(ck==0||d<int(a[st]-'0'))cnt+=(dfs2(st+1,0,rl+1,(md*10+d)%m,d)*1LL);
    else if(d==int(a[st]-'0'))cnt+=(dfs2(st+1,1,rl+1,(md*10+d)%m,d)*1LL);
  }
  else
  {
    for(int i=0;i<=9;i++)
    {
      if(i==d)continue;
      if(ck==0)
      {
        if(rl==0&&i==0)cnt+=(dfs2(st+1,0,rl,(md*10+i)%m,i)*1LL);
        else cnt+=(dfs2(st+1,0,rl+1,(md*10+i)%m,i)*1LL);
      }
      else
      {
        if(i<int(a[st]-'0'))
        {
          if(rl==0&&i==0)cnt+=(dfs2(st+1,0,rl,(md*10+i)%m,i)*1LL);
          else cnt+=(dfs2(st+1,0,rl+1,(md*10+i)%m,i)*1LL);
        }
        else if(i==int(a[st]-'0'))
        {
          if(rl==0&&i==0)cnt+=(dfs2(st+1,1,rl,(md*10+i)%m,i)*1LL);
          else cnt+=(dfs2(st+1,1,rl+1,(md*10+i)%m,i)*1LL);
        }
      }
    }
  }
  return dp[st][ck][rl%2][md][last]=cnt%mod;
}
long ck(void)
{
  long md=0;
  for(int i=0;i<a.size();i++)
  {
    if((i&1)&&int(a[i]-'0')!=d)return 0LL;
    md=(md*10+a[i]-'0')%m;
  }
  if(!md)return 1LL;
  else return 0LL;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>m>>d;
  cin>>a>>b;
   memset(dp,-1,sizeof(dp));
  long x1=dfs(0,1,0,0,0)*1LL;
  memset(dp,-1,sizeof(dp));
  cout<<(x1-dfs2(0,1,0,0,0)*1LL-ck()+mod)%mod<<endl;
  return 0;
}