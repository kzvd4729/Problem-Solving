/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 18:18                        
*  solution_verdict: Time limit exceeded on test 3           language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/633/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int aa[N+2],dp[N+2][N+2];
unordered_map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1);
  for(int i=1;i<=n;i++)
    mp[aa[i]]=i;
  int ans=0;memset(dp,-1,sizeof(dp));
  for(int i=n;i>=1;i--)
  {
    for(int j=i-1;j>=1;j--)
    {
      int f0=i,f1=j;
      int cnt=2;
      while(true)
      {
        if(dp[f0][f1]!=-1)
        {
          cnt+=dp[f0][f1];break;
        }
        if(mp[aa[f0]+aa[f1]])
        {
          cnt++;
          int f=mp[aa[f0]+aa[f1]];
          f0=f1;f1=f;
        }
        else break;
      }
      dp[i][j]=cnt;
      ans=max(ans,cnt);
    }
  }
  cout<<ans<<endl;
  return 0;
}