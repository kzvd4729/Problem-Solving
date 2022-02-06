/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1037/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long arr[N+2],s;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
  for(long i=1;i<=n;i++)
    cin>>arr[i];
  sort(arr+1,arr+n+1);
  s=abs(arr[n/2+1]-m);
  arr[n/2+1]=m;
  for(long i=1;i<=n/2+1;i++)
    if(arr[i]>m)
      s+=abs(arr[i]-m);
  for(long i=n/2+1;i<=n;i++)
    if(arr[i]<m)
      s+=abs(arr[i]-m);
  cout<<s<<endl;
  return 0;
}