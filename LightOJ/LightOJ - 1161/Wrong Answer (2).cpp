/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-23 21:01:19                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1161
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4,inf=1e9;
int aa[N+2];
vector<int>divisors(int x)
{
  int sq=sqrt(x+1);vector<int>ret;
  for(int i=1;i<=sq;i++)
  {
    if(x%i)continue;ret.push_back(i);
    if(i!=x/i)ret.push_back(x/i);
  }
  sort(ret.begin(),ret.end());
  return ret;
}
bool isOd(int x)
{
  int sq=sqrt(x+1);int cnt=0;
  for(int i=2;i<=sq;i++)
  {
    if(x%i)continue;
    cnt++;while(x%i==0)x/=i;
  }
  if(x>1)cnt++;return cnt%2;
}
long ncr(int n)
{
  return (n*(n-1)*(n-2)*(n-3))/24;
}
int cnt[N+2],pre[N+2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=2;i<=10000;i++)pre[i]=isOd(i);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      vector<int>v=divisors(x);
      for(auto x:v)cnt[x]++;
    }
    long ans=ncr(n);
    for(int i=2;i<=10000;i++)
    {
      if(pre[i])ans-=ncr(cnt[i]);
      else ans+=ncr(cnt[i]);
    }
    cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}