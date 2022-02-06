/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2018 18:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 600 KB                               
*  problem: https://codeforces.com/contest/403/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=32000;
int aa[N+2],qm[N+2];
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
  for(int i=1;i<=n;i++)
    qm[i]=__gcd(qm[i-1],aa[i]);
  // for(int i=1;i<=n;i++)
  //   cout<<qm[i]<<" ";
  // cout<<endl;
  int gcd=1;
  for(int i=n;i>=1;i--)
  {
    qm[i]/=gcd;factorize(qm[i]);
    int cnt=0;
    for(auto x:fac)
    {
      if(binary_search(bad.begin(),bad.end(),x))cnt--;
      else cnt++;
    }
    if(cnt<=0)gcd*=qm[i];
    aa[i]/=gcd;
  }
  // for(int i=1;i<=n;i++)
  //   cout<<aa[i]<<" ";
  // cout<<endl;
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