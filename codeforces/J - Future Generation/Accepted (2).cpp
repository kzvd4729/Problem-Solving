/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2019 19:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 982 ms                                          memory_used: 4400 KB                              
*  problem: https://codeforces.com/gym/102001/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int dp[15+2][(1<<15)+2];
string s[15+2],p;
vector<int>v[15+2];
bool cmp(int a,int b)
{
  string u,v;
  for(int i=0;i<15;i++)if(a&(1<<i))u.push_back(p[i]);
  for(int i=0;i<15;i++)if(b&(1<<i))v.push_back(p[i]);
  return u<v;
}
bool cmp2(pair<int,int>a,pair<int,int>b)
{
  string u,v;
  for(int i=0;i<15;i++)if(a.second&(1<<i))u.push_back(s[a.first][i]);
  for(int i=0;i<15;i++)if(b.second&(1<<i))v.push_back(s[b.first][i]);
   return u<v;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>s[i];p=s[i];int sz=p.size();
    for(int msk=1;msk<(1<<sz);msk++)
      v[i].push_back(msk);
    sort(v[i].begin(),v[i].end(),cmp);
  }
  //cout<<v[0][0]<<" "<<v[0][1]<<" "<<v[0][2]<<endl;
  memset(dp,-63,sizeof(dp));
  for(int i=v[n-1].size()-1;i>=0;i--)
    dp[n-1][i]=max(dp[n-1][i+1],__builtin_popcount(v[n-1][i]));
  for(int i=n-2;i>=0;i--)
  {
    int pt=v[i+1].size()-1;
    for(int j=v[i].size()-1;j>=0;j--)
    {
      dp[i][j]=dp[i][j+1];
      while(pt>-1)
      {
        if(cmp2({i,v[i][j]},{i+1,v[i+1][pt]}))pt--;
        else break;
      }
      dp[i][j]=max(dp[i][j],__builtin_popcount(v[i][j])+dp[i+1][pt+1]);
    }
  }
  if(dp[0][0]<0)dp[0][0]=-1;
  cout<<dp[0][0]<<endl;
  return 0;
}