/****************************************************************************************
*  @author: kzvd4729                                         created: 13-03-2021 23:50:07                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 30.6M                                
*  problem: https://www.codechef.com/MARCH21A/problems/SUBPROB
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=998244353;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int kmp[N+2];
void doKmp(string s)
{
  int n=s.size();kmp[0]=0;
  for(int i=1;i<n;i++)
  {
    int now=kmp[i-1];kmp[i]=0;
    while(true)
    {
      if(s[now]==s[i]){kmp[i]=now+1;break;}
      if(!now)break;now=kmp[now-1];
    }
  }
}
int dp[N+2],pre[N+2],suf[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string a,b;cin>>a>>b;
    doKmp(a);int n=a.size();
    for(int i=0;i<n;i++)
    {
      if(kmp[i]==0)dp[i]=1;
      else dp[i]=1+dp[kmp[i]-1];
    }
    doKmp(a+"#"+b);int m=b.size();
    for(int i=n+1;i<n+m+1;i++)
    {
      int id=i-(n+1);
      if(kmp[i]==0)pre[id]=0;
      else pre[id]=dp[kmp[i]-1];
    }
    //for(int i=0;i<m;i++)cout<<pre[i];cout<<endl;
    reverse(a.begin(),a.end());reverse(b.begin(),b.end());
    doKmp(a);n=a.size();
    for(int i=0;i<n;i++)
    {
      if(kmp[i]==0)dp[i]=1;
      else dp[i]=1+dp[kmp[i]-1];
    }
    doKmp(a+"#"+b);m=b.size();
    for(int i=n+1;i<n+m+1;i++)
    {
      int id=m-1-(i-(n+1));
      if(kmp[i]==0)suf[id]=0;
      else suf[id]=dp[kmp[i]-1];
    }
    //for(int i=0;i<m;i++)cout<<suf[i];cout<<endl;
    long ans=0;
    for(int i=0;i<m-1;i++)ans+=1LL*pre[i]*suf[i+1];
    long tt=1LL*n*n;
    ans%=mod,tt%=mod;
    cout<<(ans*big(tt,mod-2))%mod<<'\n';
  }
  return 0;
}