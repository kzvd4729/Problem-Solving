/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-10 21:33:53                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-KIDZEE1B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int t,tc=0;cin>>t;
 while(t--)
 {
  int a,b,c;cin>>a>>b>>c;
  cout<<"Case "<<++tc<<": Sum of "<<a<<", "<<b<<" and "<<c<<" is "<<a+b+c<<endl;
 }
 return 0;
}