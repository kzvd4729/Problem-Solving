/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/09/2020 20:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1312/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,R=1e16;
long aa[N+2],vis[100+2];
long cal(long b,long p)
{
  long ret=1;
  while(p--)
  {
    if(ret>R)return -1;
    ret=ret*b;
  }
  return ret;
}
long pw[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n,k;cin>>n>>k;memset(vis,0,sizeof(vis));
    for(long i=1;i<=n;i++)cin>>aa[i];
    sort(aa+1,aa+n+1);
    for(int i=0;i<70;i++)pw[i]=cal(k,i);
     int f=0;
    for(int i=n;i>=1;i--)
    {
      for(int j=70-1;j>=0;j--)
      {
        if(vis[j])continue;
        long p=pw[j];if(p==-1||p>aa[i])continue;
        aa[i]-=p;vis[j]=1;
      }
      if(aa[i])f=1;
    }
    if(f)cout<<"NO\n";else cout<<"YES\n";
  }
  return 0;
}