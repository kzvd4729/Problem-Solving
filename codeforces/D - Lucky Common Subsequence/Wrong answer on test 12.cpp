/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/11/2018 16:30                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 16900 KB                             
*  problem: https://codeforces.com/contest/347/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
string a,b,v,ans;
int kmp[N+2],dp[N+2][N+2][N+2],tmp;
pair<int,pair<int,int> >link[N+2][N+2][N+2];
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
  tmp=dfs(i+1,j,k);
  if(tmp>=here)
  {
    link[i][j][k]={i+1,{j,k}};
    here=tmp;
  }
  tmp=dfs(i,j+1,k);
  if(tmp>=here)
  {
    link[i][j][k]={i,{j+1,k}};
    here=tmp;
  }
  if(a[i]==b[j])
  {
    if(a[i]!=v[k])
    {
      if(k==0)
      {
        tmp=1+dfs(i+1,j+1,k);
        if(tmp>=here)
        {
          link[i][j][k]={i+1,{j+1,k}};
          here=tmp;
        }
      }
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
        tmp=1+dfs(i+1,j+1,now);
        if(tmp>=here)
        {
          link[i][j][k]={i+1,{j+1,now}};
          here=tmp;
        }
      }
    }
    else if(k<v.size()-1)
    {
      here=1+dfs(i+1,j+1,k+1);
      if(tmp>=here)
      {
        link[i][j][k]={i+1,{j+1,k+1}};
        here=tmp;
      }
    }
  }
  return dp[i][j][k]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b>>v;_kmp(v);
  memset(dp,-1,sizeof(dp));
  int ln=dfs(0,0,0);
  if(ln==0)cout<<0<<endl,exit(0);
  int i=0,j=0,k=0;
  while(true)
  {
    if(ln==0)break;
    pair<int,pair<int,int> >p=link[i][j][k];
    if(dp[p.first][p.second.first][p.second.second]==ln-1)
    {
      //cout<<i<<" "<<j<<" "<<k<<" "<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
      ans.push_back(a[i]);
      ln--;
    }
    i=p.first,j=p.second.first,k=p.second.second;
  }
  cout<<ans<<endl;
  return 0;
}