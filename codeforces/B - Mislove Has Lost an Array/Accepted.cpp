/****************************************************************************************
*  @author: * kzvd4729                                       created: Aug/20/2019 20:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1204/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,l,r;cin>>n>>l>>r;
  int mn=0,mx=0,pw=1;
  for(int i=1;i<=l;i++)
  {
    mn+=pw;pw+=pw;
  }
  mn+=n-l;pw=1;
  for(int i=1;i<=r;i++)
  {
    mx+=pw;pw+=pw;
  }
  mx+=(n-r)*(pw/2);
  cout<<mn<<" "<<mx<<endl;
  return 0;
}