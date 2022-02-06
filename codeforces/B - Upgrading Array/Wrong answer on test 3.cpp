/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2018 18:20                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/403/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=32000;
int aa[N+2];
vector<int>prime;int pmark[N+2];
void seive(void)
{
  int sq=sqrt(N+1);pmark[1]=1;prime.push_back(2);
  for(int i=4;i<=N;i+=2)pmark[i]=1;
  for(int i=3;i<=N;i+=2)
  {
    if(pmark[i])continue;prime.push_back(i);
    if(i>sq)continue;
    for(int j=i*i;j<=N;j+=2*i)
      pmark[j]=1;
  }
}
vector<int>fac;
void factorize(int x)
{
  fac.clear();
  for(auto xx:prime)
  {
    while(x%xx==0)
    {
      x/=xx;fac.push_back(xx);
    }
  }
  if(x!=1)fac.push_back(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);seive();
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  vector<int>bad;
  for(int i=1;i<=k;i++)
  {
    int tmp;cin>>tmp;bad.push_back(tmp);
  }
  sort(bad.begin(),bad.end());
  bad.erase(unique(bad.begin(),bad.end()),bad.end());
  for(auto x:bad)
  {
    while(true)
    {
      if(aa[1]%x)break;
      for(int i=1;i<=n;i++)
      {
        if(aa[i]%x==0)aa[i]/=x;
        else break;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    factorize(aa[i]);
    for(auto x:fac)
    {
      if(binary_search(bad.begin(),bad.end(),x))ans--;
      else ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}