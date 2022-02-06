/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2019 21:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1155/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],lt[N+2],rt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,x;cin>>n>>x;
  for(long i=1;i<=n;i++)
    cin>>aa[i];
  long sum=0,mx=0;
  for(long i=1;i<=n;i++)
  {
    sum+=aa[i];if(sum<0)sum=0;
    lt[i]=sum;
  }
  sum=0;
  for(long i=n;i>=1;i--)
  {
    sum+=aa[i];if(sum<0)sum=0;
    rt[i]=sum;
  }
  for(long i=1;i<=n;i++)aa[i]*=x;
  sum=0,mx=0;
  for(long i=1;i<=n;i++)
  {
    sum+=aa[i];sum=max(sum,lt[i]);
    mx=max(mx,sum+rt[i+1]);
  }
  cout<<mx<<endl;
  return 0;
}