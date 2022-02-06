/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2018 14:11                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/578/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;cin>>a>>b;
  if(a%b)cout<<-1<<endl;
  else if((a/b)%2)cout<<b<<endl;
  else
  {
    double ans=b*1.0+(b*1.0)/((a/b)*1.0);
    cout<<setprecision(10)<<fixed<<ans<<endl;
  }
  return 0;
}