/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/28/2018 10:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1028/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 for(int i=1;i<=2000;i++)
  s.push_back('5');
 cout<<s<<endl;s.clear();
 for(int i=1;i<2000;i++)
  s.push_back('4');
 s.push_back('5');
 cout<<s<<endl;
 return 0;
}