/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2019 16:08                        
*  solution_verdict: Time limit exceeded on test 8           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 3900 KB                              
*  problem: https://codeforces.com/gym/102001/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s[15];int dp[15][(1<<16)+2];
int cal(int msk,int id,int ln)
{
  string p;
  for(int i=0;i<15;i++)
    if(msk&(1<<i))p.push_back(s[id-1][i]);
  while(p.size()<ln)p.push_back('A'-1);
   int ret=0;
  for(int i=0;i<ln;i++)
  {
    int msk=0,pt=0,ok=1;
    for(int j=0;j<i;j++)
    {
      int f=0;
      while(pt<s[id].size())
      {
        if(p[j]==s[id][pt]){msk|=(1<<pt);pt++;f=1;break;}
        else pt++;
      }
      if(!f)ok=0;
    }
    char mn='Z'+1;
    for(int j=pt;j<s[id].size()-(ln-i-1);j++)
      if(s[id][j]>p[i])mn=min(mn,s[id][j]);
    if(mn>'Z')ok=0;int j;
    for(j=pt;j<s[id].size()-(ln-i-1);j++)
    {
      if(s[id][j]!=mn)continue;
      msk|=(1<<j);break;
    }
    int rm=ln-i-1;
    while(rm--)
    {
      mn='Z'+1;
      for(int k=j+1;k<s[id].size()-rm;k++)
        mn=min(mn,s[id][k]);
      for(int k=j+1;k<s[id].size()-rm;k++)
        if(s[id][k]==mn){msk|=(1<<k);j=k;break;}
    }
    if(ok)ret=msk;
  }
   return ret;
}
int n;
int dfs(int id,int msk)
{
  if(id==n)return 0;
  if(dp[id][msk]!=-1)return dp[id][msk];
  int ret=-inf;
  for(int i=1;i<=s[id].size();i++)
  {
    int nx=cal(msk,id,i);
    if(nx)ret=max(ret,i+dfs(id+1,nx));
  }
  return dp[id][msk]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=0;i<n;i++)cin>>s[i];
   //cout<<cal(226,2,7)<<endl;
   memset(dp,-1,sizeof(dp));
  int sz=s[0].size();
   int mx=-1;
  for(int i=1;i<(1<<sz);i++)
    mx=max(mx,__builtin_popcount(i)+dfs(1,i));
  cout<<mx<<endl;
     return 0;
}