/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2018 19:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1058/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  string s;cin>>s;
  for(int sm=0;sm<=1000;sm++)
  {
    int f=0,smm=0;
    for(auto x:s)
    {
      smm+=(x-'0');
      if(smm==sm)
      {
        smm=0;
        f++;
      }
    }
    if(smm==0&&f>1)cout<<"YES"<<endl,exit(0);
  }
  cout<<"NO"<<endl;
  return 0;
}