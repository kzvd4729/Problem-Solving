/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-31 23:39:19                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 738                                        memory_used (MB): 19.5                            
*  problem: https://vjudge.net/problem/LightOJ-1327
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int mt[15+2][15+2],n;
long dp[15+2][(1<<15)+2][2][2];
long dfs(int i,int msk,int f1,int f2)
{
  if(i==n)return f2|(!f1);
  if(dp[i][msk][f1][f2]!=-1)return dp[i][msk][f1][f2];
  long now=0;
  for(int j=0;j<n;j++)
  {
    if(msk&(1<<j))continue;
    if(!mt[i][j])now+=dfs(i+1,msk|(1<<j),1,f2);
    else if(mt[i][j]==2)now+=dfs(i+1,msk|(1<<j),f1,1);
    else now+=dfs(i+1,msk|(1<<j),f1,f2);
  }
  return dp[i][msk][f1][f2]=now;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        //mt[i][j]=rand()%2;
        cin>>mt[i][j];
      }
    }
    memset(dp,-1,sizeof(dp));
    //dfs(0,0,0,0);
    cout<<"Case "<<++tc<<": "<<dfs(0,0,0,0)<<"\n";
  }
  return 0;
}