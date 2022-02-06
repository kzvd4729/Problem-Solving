/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2019 21:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 8400 KB                              
*  problem: https://codeforces.com/contest/1194/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2],rw[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;char mt[n+2][m+2];
    for(int i=1;i<=m;i++)fr[i]=0;
    for(int i=1;i<=n;i++)rw[i]=0;
    for(int i=1;i<=n;i++)
    {
      string s;cin>>s;
      for(int j=1;j<=m;j++)
      {
        mt[i][j]=s[j-1];
        if(s[j-1]=='*')rw[i]++,fr[j]++;
      }
    }
    int ans=1e9;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        int now=n-rw[i]+m-fr[j];
        if(mt[i][j]=='.')now--;
        ans=min(ans,now);
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}