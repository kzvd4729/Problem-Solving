/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/19/2019 21:35                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1118/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  if(n>k*(k-1))cout<<"NO"<<endl,exit(0);
  cout<<"YES"<<endl;
  for(int i=1;i<=k;i++)
  {
    for(int j=i+1;j<=k;j++)
    {
      if(n)cout<<i<<" "<<j<<"\n";
      n--;
      if(n)cout<<j<<" "<<i<<"\n";
      n--;
      if(!n)break;
    }
  }
  return 0;
}