/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/04/2020 22:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 8100 KB                              
*  problem: https://codeforces.com/contest/1422/problem/C
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
const int N=1e6,mod=1e9+7;
int pw[N+2],ad[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();
   pw[0]=1,ad[0]=1;
  for(int i=1;i<=n;i++)
  {
    pw[i]=(pw[i-1]*10LL)%mod;
    ad[i]=(ad[i-1]+pw[i])%mod;
  }
  int ans=0,nm=0;
  for(int i=1;i<n;i++)
  {
    nm=(nm*10LL+s[i-1]-'0')%mod;
    ans=(ans+1LL*nm*ad[n-i-1])%mod;
  }
  nm=0;
  for(int i=n-2;i>=0;i--)
  {
    nm=(nm+1LL*(s[i+1]-'0')*pw[n-2-i])%mod;
    ans=(ans+1LL*nm*(i+1))%mod;
  }
  cout<<ans<<endl;
  return 0;
}