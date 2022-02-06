/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2018 23:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1056/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e3;
long mod[N+2],tmp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,m;cin>>n>>m;
  for(long i=0;i<m;i++)
    mod[i]=n/m;
   for(long i=1;i<=n%m;i++)
    mod[i]++;
   for(long i=0;i<m;i++)
    tmp[(i*i)%m]+=mod[i];
   long ans=tmp[0]*tmp[0];
  for(long i=1;i<m;i++)
    ans+=tmp[i]*tmp[m-i];
  cout<<ans<<endl;
  return 0;
}