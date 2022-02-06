/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2020 21:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 13900 KB                             
*  problem: https://codeforces.com/contest/1353/problem/E
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
#include<unordered_map>
#define long long long
using namespace std;
const int N=1e6;
int dp[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;string s;cin>>s;
    for(int i=n-1;i>=0;i--)
      cnt[i]=cnt[i+1]+(s[i]=='1');
    auto ret=[&](int l,int r)
    {
      if(l<0)l=0;
      return cnt[l]-cnt[r+1];
    };
    int ans=1e9;
    for(int i=0;i<k;i++)dp[i]=0;
    for(int i=0;i<s.size();i++)
    {
      dp[i%k]=min(ret(0,i),dp[i%k]+ret(i-k+1,i-1)+(s[i]=='0'));
      //cout<<i<<" "<<dp[i%k]<<endl;
      ans=min(ans,dp[i%k]+ret(i+1,n-1));
    }
    //for(int i=0;i<k;i++)ans=min(ans,dp[i]);
    cout<<ans<<"\n";
    for(int i=0;i<=n;i++)cnt[i]=0;
  }
  return 0;
}