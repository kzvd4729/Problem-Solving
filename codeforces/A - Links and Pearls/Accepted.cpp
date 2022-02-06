/****************************************************************************************
*  @author: kzvd4729                                         created: May/08/2018 21:09                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/980/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int o,m;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  for(auto x:s)
  {
    if(x=='o')o++;
    else m++;
  }
  if(o==0)cout<<"YES"<<endl;
  else if(m%o==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}