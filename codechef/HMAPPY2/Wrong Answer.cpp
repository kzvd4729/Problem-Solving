/****************************************************************************************
*  @author: kzvd4729                                         created: 01-02-2019 15:07:05                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/FEB19B/problems/HMAPPY2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,a,b,k;cin>>n>>a>>b>>k;
    long sum=(long)n/a+(long)n/b-(long)n/(a*b);
    if(sum>=k)cout<<"Win"<<endl;
    else cout<<"Lose"<<endl;
  }
  return 0;
}