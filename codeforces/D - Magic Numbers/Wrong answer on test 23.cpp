/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/20/2018 02:56                        
*  solution_verdict: Wrong answer on test 23                 language: GNU C++17                               
*  run_time: 530 ms                                          memory_used: 125700 KB                            
*  problem: https://codeforces.com/contest/628/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=2e3;
int md,d;
int dp[N+2][2][2][2][N+2];
string a,b,s;
long dfs(int st,int cnt,int f,int ck,int m)
{
  if(st==s.size())
  {
    if(m==0&&cnt)return 1LL;
    else return 0LL;
  }
  if(dp[st][cnt%2][f][ck][m]!=-1)return dp[st][cnt%2][f][ck][m]*1LL;
  long here=0,now=s[st]-'0';
  if(cnt%2==0)
  {
    if(ck&&d>now)return 0;
    if(ck&&now==d)here=(here+dfs(st+1,cnt+1,f,1,(m*10+d)%md))%mod;
    else here=(here+dfs(st+1,cnt+1,f,0,(m*10+d)%md))%mod;
  }
  else
  {
    for(int i=0;i<=9;i++)
    {
      if(i==d)continue;
      if(ck&&i>now)continue;
      if(i==0&&f==0)here=(here+dfs(st+1,cnt,0,0,m))%mod;
      if(ck&&i==now)here=(here+dfs(st+1,cnt+1,1,1,(m*10+i)%md))%mod;
      else here=(here+dfs(st+1,cnt+1,1,0,(m*10+i)%md))%mod;
    }
  }
  return dp[st][cnt%2][f][ck][m]=here%mod;
}
bool is_magic(string s)
{
  int mm=0;
  for(int i=1;i<=s.size();i++)
  {
    if(i%2==0)
      if(s[i-1]-'0'!=d)return false;
    else
      if(s[i-1]-'0'==d)return false;
    mm=(mm*10+s[i-1]-'0')%md;
  }
  return !mm;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>md>>d;
  cin>>a>>b;
  s=b;
  memset(dp,-1,sizeof(dp));
  long tmp=dfs(0,1,0,1,0);
  s=a;
  memset(dp,-1,sizeof(dp));
  tmp=(tmp-dfs(0,1,0,1,0)+mod)%mod;
   if(is_magic(s))tmp++;
  cout<<tmp%mod<<endl;
   return 0;
}