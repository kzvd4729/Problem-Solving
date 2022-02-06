/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/15/2019 21:22                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 514 ms                                          memory_used: 42300 KB                             
*  problem: https://codeforces.com/contest/1215/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e5;
int n,aa[N+2],fr[20+2],qm[20+2][N+2],po[20+2];
int mt[20+2][20+2],dp[(1<<20)+2];
vector<int>pos[20+2];
void precal(void)
{
  for(int i=0;i<n;i++)
    pos[aa[i]].push_back(i);
  for(int a=0;a<20;a++)
  {
    int pt=0;
    for(int i=0;i<n;i++)
    {
      if(i)qm[a][i]=qm[a][i-1];
      if(aa[i]==a)
        qm[a][i]++,po[a]+=i-pt++;
    }
  }
  //remove j from inside i
  for(int i=0;i<20;i++)
  {
    for(int j=0;j<20;j++)
    {
      if(i==j)continue;
      for(auto x:pos[j])
        mt[i][j]+=qm[i][n-1]-qm[i][x];
    }
  }
}
int dfs(int msk)
{
  if(__builtin_popcount(msk)==20)return 0;
  if(dp[msk]!=-1)return dp[msk];
  int now=1e9;
  for(int a=0;a<20;a++)
  {
    if(msk&(1<<a))continue;
    int ad=po[a];
    for(int b=0;b<20;b++)
      if(msk&(1<<b))ad-=mt[a][b];
    now=min(now,ad+dfs(msk|(1<<a)));
  }
  return dp[msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>aa[i];aa[i]--;
    fr[aa[i]]++;
  }
  precal();memset(dp,-1,sizeof(dp));
  cout<<dfs(0)<<endl;
  return 0;
}