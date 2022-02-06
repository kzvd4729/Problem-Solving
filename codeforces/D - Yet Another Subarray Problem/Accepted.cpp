/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2019 18:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1197/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  long ans=0;
  for(int st=1;st<=m;st++)
  {
    long sum=0;
    for(int i=st;i<=n;i+=m)
    {
      long mx=0,sm=0;
      for(int j=i;j<i+m;j++)
      {
        sm+=aa[j];mx=max(mx,sm);
      }
      sm-=k,mx-=k;
      ans=max(ans,sum+mx);
      sum+=sm;if(sum<0)sum=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}