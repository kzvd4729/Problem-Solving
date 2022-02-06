/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2018 22:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1004/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,u,v;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  while(m--)
    cin>>u>>v;
  for(int i=1;i<=n;i++)
    s.push_back(char((i%2)+'0'));
  cout<<s<<endl;
  return 0;
}