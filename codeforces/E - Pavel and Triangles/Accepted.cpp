/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2019 01:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1119/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long un=0,sm=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];sm+=aa[i];
    long mn=min(un,aa[i]/2);
    aa[i]-=mn*2;un=un-mn+aa[i]%3;
  }
  cout<<(sm-un)/3;
  return 0;
}