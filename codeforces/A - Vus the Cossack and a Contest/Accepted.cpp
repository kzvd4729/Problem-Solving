/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2019 23:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1186/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,c;cin>>a>>b>>c;
  if(min(b,c)>=a)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}