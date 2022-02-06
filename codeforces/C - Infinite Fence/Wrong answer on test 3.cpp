/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/27/2019 20:33                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1260/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b,k;cin>>a>>b>>k;
    if(a==b)cout<<"OBEY\n";
    else
    {
      if(a>b)swap(a,b);
      if((b-1)/a>=k)cout<<"REBEL\n";
      else cout<<"OBEY\n";
    }
  }
    return 0;
}