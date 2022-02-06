/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/11/2018 19:00                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/347/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
string a,b,v,ans;
int kmp[N+2],dp[N+2][N+2][N+2];
void _kmp(string s)
{
  kmp[0]=0;
  for(int i=1;s[i];i++)
  {
    int now=kmp[i-1];
    while(true)
    {
      if(s[now]==s[i])
      {
        kmp[i]=now+1;
        break;
      }
      if(!now)break;
      now=kmp[now-1];
    }
  }
}
int dfs(int i,int j,int k)
{
  if(i>=a.size()||j>=b.size())return dp[i][j][k]=0;
  if(dp[i][j][k]!=-1)return dp[i][j][k];
  int here=0;
  here=max(here,dfs(i+1,j,k));
  here=max(here,dfs(i,j+1,k));
  if(a[i]==b[j])
  {
    if(a[i]!=v[k])
    {
      if(k==0)here=max(here,1+dfs(i+1,j+1,k));
      else
      {
        int now=kmp[k-1];
        while(true)
        {
          if(v[now]==a[i])
          {
            now++;
            break;
          }
          if(!now)break;
          now=kmp[now-1];
        }
        here=max(here,1+dfs(i+1,j+1,now));
      }
    }
    else if(k<v.size()-1)
      here=max(here,1+dfs(i+1,j+1,k+1));
  }
  return dp[i][j][k]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b>>v;_kmp(v);
  memset(dp,-1,sizeof(dp));
  int ln=dfs(0,0,0);
 //  for(int i=0;i<a.size();i++)
//  {
//    for(int j=0;j<b.size();j++)
//    {
//      for(int k=0;k<v.size();k++)
//      {
//        cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
//      }
//    }
//  }
   int i=0,j=0;
  while(true)
  {
    if(ln==0)break;
    int f=0;
    for(int k=0;k<v.size();k++)
    {
      if(dp[i+1][j+1][k]==ln-1&&a[i]==b[j])
      {
        ans.push_back(a[i]);
        f=1,i++,j++,ln--;
        break;
      }
    }
    if(f)continue;
    for(int k=0;k<v.size();k++)
    {
      if(dp[i+1][j][k]==ln)
      {
        f=1,i++;
        break;
      }
    }
    if(f)continue;
    for(int k=0;k<v.size();k++)
    {
      if(dp[i][j+1][k]==ln)
      {
        f=1,j++;
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}