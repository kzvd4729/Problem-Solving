/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/19/2019 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1141/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>aa[i];aa[i+n]=aa[i];
 }
 n*=2;int cnt=0,mx=0;
 for(int i=1;i<=n+1;i++)
 {
  if(aa[i])cnt++;
  else
  {
   mx=max(mx,cnt);
   cnt=0;
  }
 }
 cout<<mx<<endl;
 return 0;
}