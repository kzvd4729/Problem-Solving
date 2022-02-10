/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-04 21:05:09                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1140
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,m,lm,tc;
long a,b,dp[10][2][10];
vector<long>arr;
void make_array(long x)
{
  arr.clear();
  while(x)
  {
    arr.push_back(x%10);
    x/=10;
  }
  lm=arr.size();
  reverse(arr.begin(),arr.end());
}
long dfs(long st,long ck,long cnt,long f)
{
  if(st>=lm)return cnt*1LL;
  if(dp[st][ck][cnt]!=-1)return dp[st][ck][cnt];
  long here=0;
  for(long i=0;i<10;i++)
  {
    if(ck==0)
    {
      if(i==0&&f==0)here+=dfs(st+1,0,cnt,f);
      else if(i==0)here+=dfs(st+1,0,cnt+1,1);
      else here+=dfs(st+1,0,cnt,1);
    }
    else
    {
      if(i>arr[st])continue;
      else if(i<arr[st])
      {
        if(i==0&&f==0)here+=dfs(st+1,0,cnt,f);
        else if(i==0)here+=dfs(st+1,0,cnt+1,1);
        else here+=dfs(st+1,0,cnt,1);
      }
      else
      {
        if(i==0)here+=dfs(st+1,1,cnt+1,1);
        else here+=dfs(st+1,1,cnt,1);
      }
    }
  }
  return dp[st][ck][cnt]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    make_array(m);
    memset(dp,-1,sizeof(dp));
    b=dfs(0,1,0,0);


    if(n==0)
      cout<<"Case "<<++tc<<": "<<b+1<<endl;
    else
    {
      make_array(n-1);
      memset(dp,-1,sizeof(dp));
      a=dfs(0,1,0,0);
      cout<<"Case "<<++tc<<": "<<b-a<<endl;
    }
  }
  return 0;
}