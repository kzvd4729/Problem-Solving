/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2020 20:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1285/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  int ng=0,ps=0;
  for(auto x:s)
  {
    if(x=='L')ng--;else ps++;
  }
  cout<<ps-ng+1<<endl;
    return 0;
}