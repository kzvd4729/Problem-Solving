/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2020 00:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 52700 KB                             
*  problem: https://codeforces.com/contest/1240/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],p[N+2],par[N+2];
long dp[N+2];map<int,int>mp[N+2];
int get(int x)
{
  if(x==par[x])return par[x];
  return par[x]=get(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n+1;i++)par[i]=i,mp[i].clear();
    mp[n][a[n]]=n;
    p[n]=-1;p[n+1]=-1;a[n+1]=-1;
    for(int i=n-1;i>=1;i--)
    {
      int j=i+1;p[i]=-1;
       int r1=get(j);
      if(mp[r1].count(a[i])==0)
      {
        mp[i][a[i]]=i;
      }
      else
      {
        p[i]=mp[r1][a[i]];
        int r2=get(p[i]+1);par[i]=r2;
        mp[r2][a[i]]=i;
      }
    }
    //for(int i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
    dp[n]=0;dp[n+1]=0;long ans=0;
    for(int i=n-1;i>=1;i--)
    {
      if(p[i]==-1)dp[i]=0;
      else dp[i]=1+dp[p[i]+1];
      ans+=dp[i];
    }
    cout<<ans<<" ";
  }
  return 0;
}