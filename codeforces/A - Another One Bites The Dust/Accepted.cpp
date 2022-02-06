/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/13/2019 18:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1148/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long a,b,c;cin>>a>>b>>c;
  if(a==b)cout<<c+c+a+b<<endl;
  else cout<<c+c+min(a,b)*2+1<<endl;
  return 0;
}