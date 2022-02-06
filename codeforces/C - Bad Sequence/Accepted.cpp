/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/04/2019 15:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1214/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  int bl=0,mn=1e9;
  for(auto x:s)
  {
    if(x=='(')bl++;
    else bl--;
    mn=min(mn,bl);
  }
  if(bl==0&&mn>=-1)cout<<"Yes\n";
  else cout<<"No\n";
  return 0;
}