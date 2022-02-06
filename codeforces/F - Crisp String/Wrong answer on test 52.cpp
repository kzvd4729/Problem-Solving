/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2020 23:48                        
*  solution_verdict: Wrong answer on test 52                 language: GNU C++14                               
*  run_time: 1980 ms                                         memory_used: 71500 KB                             
*  problem: https://codeforces.com/contest/1117/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int a[20+2][20+2],c[20+2][N+2],dp[(1<<17)+2],n,p;
int cal(int i,int j,int k)
{
  if(j==0)return c[i][k];
  return c[i][k]-c[i][j-1];
}
int goRGT(int i,int j,int id)
{
  if(id==n-1||cal(j,id+1,n-1)==0)return -1;
  int lo=id+1,hi=n-1,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(cal(j,id+1,md))hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(cal(j,id+1,md))break;
  int msk=0;
  for(int k=0;k<p;k++)
    if(cal(k,id+1,md-1))msk|=(1<<k);
  if(msk&(1<<i))msk^=(1<<i);
  return msk;
}
int goLFT(int i,int j,int id)
{
  if(id==0||cal(j,0,id-1)==0)return -1;
  int lo=0,hi=id-1,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(cal(j,md,id-1))lo=md;
    else hi=md;
  }
  for(md=hi;md>=lo;md--)
    if(cal(j,md,id-1))break;
  int msk=0;
  for(int k=0;k<p;k++)
    if(cal(k,md+1,id-1))msk|=(1<<k);
  if(msk&(1<<i))msk^=(1<<i);
  return msk;
}
bool bad[20+2][20+2][(1<<17)+2];
int rm[20+2];
int dfs(int msk)
{
  //cout<<msk<<endl;
  if(dp[msk]!=-1)return dp[msk];
  int com=((1<<p)-1)^msk;
  if(__builtin_popcount(com)<=2)
  {
    int ret=0;
    for(int i=0;i<p;i++)if(com&(1<<i))ret+=cal(i,0,n-1);
    return dp[msk]=ret;
  }
  int ret=0;
  for(int i=0;i<p;i++)
  {
    if(msk&(1<<i))continue;int tmp=msk|(1<<i),tcom=com^(1<<i);
    int f=0;
    for(int j=0;j<p;j++)
    {
      if(i==j)continue;
      for(int k=0;k<p;k++)
      {
        if(bad[j][k][tmp]&&((tcom&(1<<j))&&(tcom&(1<<k))))
        {
          f=1;break;
        }
      }
      if(f)break;
    }
    if(!f)ret=max(ret,cal(i,0,n-1)+dfs(msk|(1<<i)));
  }
  return dp[msk]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>p;string s;cin>>s;
  for(int i=0;i<p;i++)
  {
    for(int j=0;j<p;j++)cin>>a[i][j];
  }
  c[s[0]-'a'][0]++;
  for(int i=1;i<n;i++)
  {
    for(int j=0;j<p;j++)c[j][i]=c[j][i-1];
    c[s[i]-'a'][i]++;
  }
  memset(dp,-1,sizeof(dp));
  for(int id=0;id<n;id++)
  {
    int i=s[id]-'a';
    for(int j=0;j<p;j++)
    {
      if(a[i][j])continue;
      int ms=goLFT(i,j,id);
      if(ms!=-1)bad[i][j][ms]=1;
       //if(ms!=-1)cout<<id<<" - "<<i<<" "<<j<<" "<<ms<<endl;
       ms=goRGT(i,j,id);
      if(ms!=-1)bad[i][j][ms]=1;
      //if(ms!=-1)cout<<id<<" + "<<i<<" "<<j<<" "<<ms<<endl;
    }
  }
  for(int i=0;i<p;i++)
  {
    for(int j=0;j<p;j++)
    {
      int ad=(1<<i)|(1<<j);
      for(int msk=1;msk<(1<<p);msk++)
      {
        if(msk&ad)continue;
        for(int k=0;k<p;k++)
          if(msk&(1<<k))bad[i][j][msk]|=bad[i][j][msk^(1<<k)];
      }
    }
  }
  cout<<n-dfs(0)<<endl;
  return 0;
}