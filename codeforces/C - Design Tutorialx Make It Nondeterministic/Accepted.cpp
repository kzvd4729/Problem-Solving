/****************************************************************************************
*  @author: kzvd4729                                         created: May/24/2020 17:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 135100 KB                            
*  problem: https://codeforces.com/contest/472/problem/C
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
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
struct data
{
  string a,b;
}aa[N+2];
string s1[N+2],s2[N+2];
int dp[N+2][2+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;aa[i]={s1[x],s2[x]};
  }
  //for(int i=1;i<=n;i++)cout<<aa[i].a<<" "<<aa[i].b<<endl;
  dp[1][0]=1;dp[1][1]=1;
  for(int i=2;i<=n;i++)
  {
    if(aa[i].a>aa[i-1].a)dp[i][0]|=dp[i-1][0];
    if(aa[i].a>aa[i-1].b)dp[i][0]|=dp[i-1][1];
    if(aa[i].b>aa[i-1].a)dp[i][1]|=dp[i-1][0];
    if(aa[i].b>aa[i-1].b)dp[i][1]|=dp[i-1][1];
    //cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
  }
  if(dp[n][0]|dp[n][1])cout<<"YES\n";
  else cout<<"NO\n";
  return 0;
}