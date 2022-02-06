/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/15/2019 21:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 888 ms                                          memory_used: 88300 KB                             
*  problem: https://codeforces.com/contest/1215/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=4e5;
long n,aa[N+2],fr[20+2],qm[20+2][N+2],po[20+2];
long mt[20+2][20+2],dp[(1<<20)+2];
vector<long>pos[20+2];
void precal(void)
{
  for(long i=0;i<n;i++)
    pos[aa[i]].push_back(i);
  for(long a=0;a<20;a++)
  {
    long pt=0;
    for(long i=0;i<n;i++)
    {
      if(i)qm[a][i]=qm[a][i-1];
      if(aa[i]==a)
        qm[a][i]++,po[a]+=i-pt++;
    }
  }
  //remove j from inside i
  for(long i=0;i<20;i++)
  {
    for(long j=0;j<20;j++)
    {
      if(i==j)continue;
      for(auto x:pos[j])
        mt[i][j]+=qm[i][n-1]-qm[i][x];
    }
  }
}
long dfs(long msk)
{
  if(__builtin_popcount(msk)==20)return 0;
  if(dp[msk]!=-1)return dp[msk];
  long now=1e15;
  for(long a=0;a<20;a++)
  {
    if(msk&(1<<a))continue;
    long ad=po[a];
    for(long b=0;b<20;b++)
      if(msk&(1<<b))ad-=mt[a][b];
    now=min(now,ad+dfs(msk|(1<<a)));
  }
  return dp[msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(long i=0;i<n;i++)
  {
    cin>>aa[i];aa[i]--;
    fr[aa[i]]++;
  }
  precal();memset(dp,-1,sizeof(dp));
  cout<<dfs(0)<<endl;
  return 0;
}