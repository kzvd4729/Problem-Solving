/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/10/2018 22:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 11200 KB                             
*  problem: https://codeforces.com/contest/948/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long n,vis[N+2],x1,ns,ans=1e8,mm;
vector<long>fc,pr;
void find_prime(void)
{
  pr.push_back(2);
  for(long i=4;i<=N;i+=2)vis[i]=1;
  for(long i=3;i<=N;i+=2)
  {
    if(vis[i])continue;
    pr.push_back(i);
    for(long j=i*i;j<=N;j+=2*i)vis[j]=1;
  }
}
void prime_factorize(long n)
{
  for(long i=2;i<=n;i++)
  {
    if(n%i==0)
    {
      fc.push_back(i);
      while(n%i==0)n=n/i;
    }
  }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     find_prime();
     cin>>n;
    prime_factorize(n);
     for(auto x:fc)
    {
      x1=x*((n/x)-1)+1;
      for(auto z:pr)
      {
        if(z>n)break;
        mm=(x1-1)/z;
        mm++;
        if(mm*z>n||mm*z<x1)continue;
        ns=z*(mm-1)+1;
        if(ns<3)continue;
        ans=min(ans,ns);
      }
    }
    cout<<ans<<endl;
    return 0;
}