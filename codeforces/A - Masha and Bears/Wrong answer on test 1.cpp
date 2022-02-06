/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/24/2017 13:44                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/907/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c,d;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
        cin>>a>>b>>c>>d;
    if(d<=c&&2*d>=c&&2*d<b)
    {
      cout<<c<<endl<<b<<endl<<a<<endl;
  }
  else cout<<-1<<endl;
  return 0;
}