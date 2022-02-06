/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2018 19:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/301/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int mx=1e9,sum=0,ng=0;
  for(int i=1;i<n+n;i++)
  {
    cin>>aa[i];sum+=abs(aa[i]);
    mx=min(mx,abs(aa[i]));
    if(aa[i]<=0)ng++;
  }
  if(ng%2)
    if(n%2==0)sum-=(mx+mx);
  cout<<sum<<endl;
  return 0;
}