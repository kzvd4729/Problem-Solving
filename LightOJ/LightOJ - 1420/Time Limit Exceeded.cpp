/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-09 16:45:41                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1420
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
const long mod=1000000007;
int dp[N+2][N+2][N+2];
string a,b,c;
vector<int>po[3][30];
long dfs(int i,int j,int k)
{
  if(k>=c.size())return 1;
  if(dp[i][j][k]!=-1)return dp[i][j][k];
  int l=c[k]-'a';
  long now=0;
  int id1=lower_bound(po[1][l].begin(),po[1][l].end(),i)-po[1][l].begin();
  int id2=lower_bound(po[2][l].begin(),po[2][l].end(),j)-po[2][l].begin();
  for(int f=id1;f<po[1][l].size();f++)
    now=(now+dfs(po[1][l][f]+1,j,k+1))%mod;
  for(int f=id2;f<po[2][l].size();f++)
    now=(now+dfs(i,po[2][l][f]+1,k+1))%mod;
  return dp[i][j][k]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>a>>b>>c;
    /*a.clear();b.clear();c.clear();
    for(int i=0;i<100;i++)
    {
      a.push_back('a');
      b.push_back('a');
      c.push_back('a');
    }*/
    for(int i=0;i<26;i++)po[1][i].clear(),po[2][i].clear();
    for(int i=0;i<a.size();i++)
      po[1][a[i]-'a'].push_back(i);
    for(int i=0;i<b.size();i++)
      po[2][b[i]-'a'].push_back(i);
    memset(dp,0,sizeof(dp));

    for(int i=0;i<=a.size();i++)
      for(int j=0;j<=b.size();j++)
        dp[i][j][c.size()]=1;
    for(int k=c.size()-1;k>=0;k--)
    {
      for(int i=a.size();i>=0;i--)
      {
        for(int j=b.size();j>=0;j--)
        {
          int l=c[k]-'a';long now=0;
          int id1=lower_bound(po[1][l].begin(),po[1][l].end(),i)-po[1][l].begin();
          int id2=lower_bound(po[2][l].begin(),po[2][l].end(),j)-po[2][l].begin();
          for(int f=id1;f<po[1][l].size();f++)
            now=(now+dp[po[1][l][f]+1][j][k+1])%mod;
          for(int f=id2;f<po[2][l].size();f++)
            now=(now+dp[i][po[2][l][f]+1][k+1])%mod;
          dp[i][j][k]=now;
        }
      }
    }
    cout<<"Case "<<++tc<<": "<<dp[0][0][0]<<"\n";
  }
  return 0;
}