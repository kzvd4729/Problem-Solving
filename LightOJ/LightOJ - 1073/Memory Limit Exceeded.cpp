/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-31 20:15:10                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1073
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e5;
int t,tc,n,kmp[204],mat[20][20];
string dp[(1<<15)+2][16];
string s[20];
int _kmp(string ss,int id)
{
  memset(kmp,0,sizeof(kmp));
  int mx=0;
  for(int i=1;i<ss.size();i++)
  {
    int now=kmp[i-1];
    while(true)
    {
      if(ss[i]==ss[now])
      {
        kmp[i]=now+1;
        break;
      }
      if(!now)break;
      now=kmp[now-1];
    }
  }
  for(int i=id+1;i<ss.size();i++)
    if(kmp[i]==id)return id;
  return kmp[ss.size()-1];
}
void generate_kmp_table(void)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==j)continue;
      string tmp=s[j]+"#"+s[i];
      mat[i][j]=_kmp(tmp,s[j].size());
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>s[i];
    generate_kmp_table();

    for(int i=0;i<(1<<n);i++)
      for(int j=0;j<n;j++)
        dp[i][j].clear();

    for(int i=0;i<n;i++)
    {
      int msk=(1<<i);
      dp[msk][i]=s[i];
    }
    for(int i=1;i<(1<<n);i++)
    {
      for(int j=0;j<n;j++)
      {
        if(dp[i][j].size()==0)continue;
        for(int k=0;k<n;k++)
        {
          if(i&(1<<k))continue;
          int msk=i|(1<<k);
          int ln=dp[i][j].size()+s[k].size()-mat[j][k];
          if(dp[msk][k].size()==0)
          {
            string tmp=dp[i][j];
            for(int ii=mat[j][k];ii<s[k].size();ii++)
              tmp.push_back(s[k][ii]);
            dp[msk][k]=tmp;
            continue;
          }
          if(ln>dp[msk][k].size())continue;
          string tmp=dp[i][j];
          for(int ii=mat[j][k];ii<s[k].size();ii++)
            tmp.push_back(s[k][ii]);
          if(tmp.size()<dp[msk][k].size())dp[msk][k]=tmp;
          else dp[msk][k]=min(dp[msk][k],tmp);
        }
      }
    }
    string ans;
    for(int i=0;i<inf;i++)ans.push_back('z');
    for(int i=0;i<n;i++)
    {
      if(dp[(1<<n)-1][i].size()>ans.size())continue;
      if(dp[(1<<n)-1][i].size()<ans.size())
        ans=dp[(1<<n)-1][i];
      else if(dp[(1<<n)-1][i].size()==ans.size())
        ans=min(ans,dp[(1<<n)-1][i]);
    }
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}